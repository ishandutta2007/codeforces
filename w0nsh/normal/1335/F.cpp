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

PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}
int n, m, N;
VI A;
std::vector<PII> dir;
std::vector<VI> g;
VI next;

bool bounds(PII a){
	return a.X >= 0 && a.Y >= 0 && a.X < n && a.Y < m;
}
int ind(PII a){
	return a.X*m+a.Y;
}
PII pair(int in){
	return MP(in/m, in%m);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		N = n*m;
		A.resize(N);
		FOR(i, n){
			FOR(j, m){
				char a;
				std::cin >> a;
				if(a == '1') A[i*m+j] = 0;
				else A[i*m+j] = 1;
			}
		}
		dir = std::vector<PII>();
		FOR(i, n){
			FOR(j, m){
				char a;
				std::cin >> a;
				if(a == 'U') dir.push_back(MP(-1, 0));
				if(a == 'D') dir.push_back(MP(1, 0));
				if(a == 'L') dir.push_back(MP(0, -1));
				if(a == 'R') dir.push_back(MP(0, 1));
			}
		}
		next.resize(N);
		g = std::vector<VI>(N);
		FOR(i, N){
			int pr = ind(pair(i)+dir[i]);
			next[i] = pr;
			g[pr].push_back(i);
		}
		VI vis(N);
		int tick = 1;
		std::vector<VI> cycles;
		std::vector<bool> oncy(N);
		FOR(i, N) if(vis[i] == 0){
			tick++;
			VI stack;
			stack.push_back(i);
			while(true){
				int cur = stack.back();
				vis[cur] = tick;
				if(vis[next[cur]] == 0) stack.push_back(next[cur]);
				else{
					if(vis[next[cur]] == tick){
						cycles.emplace_back();
						int moj = next[cur];
						oncy[moj] = true;
						while(stack.back() != moj) cycles.back().push_back(stack.back()),
													oncy[stack.back()] = true,
													stack.pop_back();
						cycles.back().push_back(moj);
						std::reverse(cycles.back().begin(), cycles.back().end());
					}
					break;
				}
			}
		}
		/*
		TRAV(c, cycles){
			TRAV(i, c) std::cout << pair(i).X << "," << pair(i).Y << " ";
			std::cout << std::endl;
		}
		std::cout << "===" << std::endl;
		*/
		PII ans = MP(0, 0);
		TRAV(c, cycles){
			std::set<int> mam;
			std::function<void(int, int)> dfs = [&](int v, int kto){
				if(A[v]) mam.insert(kto);
				TRAV(ch, g[v]) if(!oncy[ch]){
					dfs(ch, (kto-1+SZ(c))%SZ(c));
				}
			};
			FOR(i, SZ(c)) dfs(c[i], i);
			ans.X += SZ(c);
			ans.Y += SZ(mam);
		}
		std::cout << ans.X << " " << ans.Y << "\n";
	}

	return 0;
}