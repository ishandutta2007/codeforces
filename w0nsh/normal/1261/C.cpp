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

std::vector<std::vector<bool> > tab;
std::vector<std::vector<bool> > st;

PII operator - (PII a, PII b){
	return MP(a.X-b.X, a.Y-b.Y);
}

PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

	int n, m;
std::vector<PII> dirs = {MP(1, 0), MP(-1, 0), MP(0, 1), MP(0, -1),
						MP(1, 1), MP(-1, 1), MP(-1, -1), MP(1, -1)};

bool bounds(PII a){
	return a.X >= 0 && a.X < n && a.Y >= 0 && a.Y < m;
}

std::vector<PII> start;
std::vector<VI> vis;

void wyp(std::vector<PII> xdd){
	std::set<PII> set;
	TRAV(i, xdd) set.insert(i);
	FOR(i, n){
		FOR(j, m){
			std::cout << (set.count(MP(i, j)) == 1 ? 'X' : '.');

		}
		std::cout << std::endl;
	}
}

int IND;

bool check(int k, bool write=false){
	IND++;
	std::queue<PR<PII, int> > que;
	TRAV(i, start) que.push(MP(i, k)), vis[i.X][i.Y] = IND;
	std::vector<PII> my;
	while(SZ(que)){
		auto cur = que.front();
		que.pop();
		PII v = cur.X;
		int dis = cur.Y;
		TRAV(d, dirs){
			PII nxt = d + v;
			if(bounds(nxt) && tab[nxt.X][nxt.Y] && vis[nxt.X][nxt.Y] != IND){
				vis[nxt.X][nxt.Y] = IND;
				que.push(MP(nxt, dis-1));
				//if(dis-1 < 0) return false;
				if(dis-1 <= 0) my.push_back(nxt);
			}
		}
	}
	IND++;
	TRAV(i, my) vis[i.X][i.Y] = IND, que.push(MP(i, 0));
	std::vector<PII> wyn;
	int need = SZ(start);
	while(SZ(que)){
		auto cur = que.front();
		que.pop();
		PII v = cur.X;
		int dis = cur.Y;
		TRAV(d, dirs){
			PII nxt = d+v;
			if(bounds(nxt) && vis[nxt.X][nxt.Y] != IND){
				if(!tab[nxt.X][nxt.Y]) return false;
				vis[nxt.X][nxt.Y] = IND;
				if(st[nxt.X][nxt.Y] && dis+1 != k) return false;
				if(dis+1 == k){
					if(st[nxt.X][nxt.Y]) need--;
		//			wyn.push_back(nxt);
				}
				else que.push(MP(nxt, dis+1));
			}
		}
	}
	//std::cout << "k " << k << std::endl;
	//wyp(wyn);
	//std::cout << "===================\n";
	//wyp(start);
	if(need != 0) return false;
	if(write){
		std::vector<std::vector<bool> > ans;
		ans.resize(n, std::vector<bool>(m));
		TRAV(i, my) ans[i.X][i.Y] = true;
		REP(i, 1, n-1){
			REP(j, 1, m-1){
				if(ans[i][j]) std::cout << 'X';
				else std::cout << '.';
			}
			std::cout << "\n";
		}
	}
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	n += 2;
	m += 2;
	tab.resize(n, std::vector<bool>(m));
	st.resize(n, std::vector<bool>(m));
	vis.resize(n, VI(m));
	REP(i, 1, n-1){
		REP(j, 1, m-1){
		char xd;
		std::cin >> xd;
			tab[i][j] = (xd == 'X');
		}
	}
	FOR(i, n){
		FOR(j, m){
			if(!tab[i][j]) continue;
			bool ss = false;
			TRAV(d, dirs){
				PII xd = MP(i, j) + d;
				if(bounds(xd)){
					if(!tab[xd.X][xd.Y]) ss = true;
				}else ss = true;
			}
			if(ss) st[i][j] = true, start.push_back(MP(i, j));
			
		}
	}
	std::sort(start.begin(), start.end());
	int left = 1;
	int right = n+m+1;
	while(left < right){
		int mid = (left+right)/2;
		if(check(mid)) left = mid+1;
		else right = mid;
	}
	left--;
	std::cout << left << "\n";
	if(left == 0){
		REP(i, 1, n-1){
			REP(j, 1, m-1){
				std::cout << (tab[i][j] ? 'X' : '.');
			}
			std::cout << "\n";
		}
	}else check(left, true);
	return 0;
}