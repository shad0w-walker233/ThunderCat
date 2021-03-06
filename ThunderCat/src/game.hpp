//
#ifndef game_hpp
#define game_hpp

#include "utility.h"
#include "trajectory.hpp"
#include "status.hpp"
#include "monster.h"
#include "hero.hpp"
#include "mix_sound.hpp"

class Game{
private:
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Event event;
	Trajectory tra, guidetra;
	Life life;
	Score score;
	Lightning lightning;
	vector<Monster> monsters;
	Hero hero;
	int monster_number;
	SDL_Texture *bgTexture, *pausebotton, *restartbotton, *pausetex, *wintex, *losetex;
	bool ingame;
	bool quit;
	EffectSound *die, *win1, *win2, *endlessend, *lose, *start, *click;
	MusicSound *menubgm, *normalbgm, *endlessbgm;
	int comb;
	bool guidemode;
	SDL_Point lastguide;
	SDL_Texture *guidetext;
public:
	Game();
	~Game();
	void run();
	int stage();
	void defaultRender();
	void show(SDL_Texture *extra_tex, const SDL_Rect *extra_rect, bool only_extra, bool refresh);
	int welcome();
	void createMonster(int m_number);
	void scoll(const string& bgName);
	void normal();
	void endless();
	void lose_scene();
	void win_scene();
	void story_scene(int num);
	void op();
	void pause_scene();
	void wait_for_click();
	void guide();
};

#endif /* game_hpp */
