#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int t[1005][1005];
int kiedy[1005][1005];

int n, m, qqq;
PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

std::vector<PII> dirs{MP(0, 1), MP(0, -1), MP(1, 0), MP(-1, 0)};

bool bounds(PII a){
	return a.X >= 1 && a.X <= n && a.Y >= 1 && a.Y <= m;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> qqq;
	REP(i, 1, n+1){
		REP(j, 1, m+1){
			char a;
			std::cin >> a;
			if(a == '0'){
				t[i][j] = 0;
			}else{
				t[i][j] = 1;
			}
		}
	}

	REP(i, 1, n+1){
		REP(j, 1, m+1){
			TRAV(d, dirs){
				PII pos = MP(i, j) + d;
				if(!bounds(pos)) continue;
				if(t[pos.X][pos.Y] == t[i][j]) kiedy[i][j] = 1;
			}
		}
	}
	
	std::queue<PII> que;
	REP(i, 1, n+1){
		REP(j, 1, m+1){
			if(kiedy[i][j] == 1) que.push(MP(i, j));
		}
	}

	while(SZ(que)){
		auto cur = que.front();
		que.pop();
		TRAV(d, dirs){
			auto pos = d+cur;
			if(!bounds(pos)) continue;
			if(kiedy[pos.X][pos.Y] == 0){
				kiedy[pos.X][pos.Y] = kiedy[cur.X][cur.Y] + 1;
				que.push(pos);
			}
		}
	}
	/*
	REP(i, 1, n+1){
		REP(j, 1, m+1){
			std::cout << kiedy[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/

	FOR(_, qqq){
		ll a, b, c;
		std::cin >> a >> b >> c;
		if(kiedy[a][b] == 0){
			std::cout << t[a][b] << "\n";
		}else{
			if(c < kiedy[a][b]) std::cout << t[a][b] << "\n";
			else if((c-kiedy[a][b])%2 == 0) std::cout << 1-t[a][b] << "\n";
			else std::cout << t[a][b] << "\n";
		}
	}


	return 0;
}