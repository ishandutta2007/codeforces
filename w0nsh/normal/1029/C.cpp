#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Event{
	int p, i;
	bool b;
	Event(){}
	Event(int _p, int _i, bool _o):  p(_p), i(_i), b(_o) {}
};

struct CMP{
	bool operator() (const Event &a, const Event &b){
		return a.p < b.p;
	}
};

int n;
std::vector<Event> events;
std::vector<PII> seg;

int intersection_without(std::vector<Event> &vec, int without){
	int opened = 0;
	int last = vec[0].p;
	FOR(i, SZ(vec)){
		auto &ev = vec[i];
		if(ev.i == without) continue;
		if(opened == n-1){
			return ev.p - last;
		}
		if(!ev.b) return 0;
		opened++;
		last = ev.p;
	}
	return 0;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	events.reserve(n);
	seg.reserve(n);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		seg.push_back({a, b});
	}
	std::sort(seg.begin(), seg.end());
	FOR(i, n){
		events.push_back(Event(seg[i].X, i, true));
		events.push_back(Event(seg[i].Y, i, false));
	}
	std::sort(events.begin(), events.end(), CMP());
	FOR(i, n){
		if(seg[i].X == seg[i].Y){
			std::cout << intersection_without(events, i) << "\n";
			return 0;
		}
	}
	int opened = 0;
	int fs = -1, sc = -1;
	PII good = MP(0, 0);
	FOR(i, SZ(events)){
		auto &ev = events[i];
		if(ev.b){
			opened++;
			if(opened == n) good.X = ev.p;
			if(fs != -1){
				sc = ev.i;
				break;
			}
		}else{
			if(opened == n){
				good.Y = ev.p;
				break;
			}
			else fs = ev.i;
		}
	}
	if(fs == -1){
		int cl = 2000000666, cr = -20;
		FOR(i, n){
			auto &s = seg[i];
			if(s.X == good.X && s.Y < cl) fs = i, cl = s.Y;
			if(s.Y == good.Y && s.X > cr) sc = i, cr = s.X;
		}
	}
	std::cout << std::max(intersection_without(events, fs), intersection_without(events, sc)) << "\n";
	return 0;
}