#include <bits/stdc++.h>
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

int n, m, a, b;
int tab[3005][3005];
int bot[3005][3005];

struct Kmin{
	int sz;
	std::deque<PII> deq;
	int min(){
		return deq.front().X;
	}

	void push_back(int val){
		int ile = 0;
		while(!deq.empty() && deq.back().X > val) ile += deq.back().Y+1, deq.pop_back(); 
		deq.push_back(MP(val, ile));
		sz++;
	}

	void pop_front(){
		if(deq.front().Y == 0) deq.pop_front();
		else deq.front().Y--;
		sz--;
	}

};

void readtab(){
	int g0, x, y, z;
	std::cin >> g0 >> x >> y >> z;
	FOR(i, n){
		FOR(j, m){
			tab[i][j] = g0;
			g0 = (1ll*g0*x + y)%z;
		}
	}
}

int minx[3005][3005];
int XDDD[3005][3005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> a >> b;
	readtab();
	FOR(i, n){
		Kmin que;
		que.sz = 0;
		FOR(j, m){
			que.push_back(tab[i][j]);
			if(que.sz > b) que.pop_front();
			if(que.sz == b){
				minx[i][j] = que.min();
			}
		}
	}
	REP(j, b-1, m){
		Kmin que;
		que.sz = 0;
		FOR(i, n){
			que.push_back(minx[i][j]);
			if(que.sz > a) que.pop_front();
			if(que.sz == a){
				XDDD[i][j] = que.min();
			}
		}
	}
	ll ans = 0;
	REP(i, a-1, n){
		REP(j, b-1, m){
			ans += XDDD[i][j];
		}
	}
	std::cout << ans;
	return 0;
}