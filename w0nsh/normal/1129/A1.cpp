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

int n, m;
std::vector<VI> g;
std::vector<int> kt;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
	}
	FOR(i, n) std::sort(g[i].begin(), g[i].end(), [&](const int &a, const int &b){
		return a-i+(i>a ? n : 0) < b-i+(i>b ? n : 0);
	});
	int mx = 0;
	FOR(i, n){
		mx = std::max(mx, SZ(g[i]));
	}
	int todo = 0;
	FOR(i, n){
		// FOR(j, mx-3){
		// 	if(g[i].empty()) break;
		// 	g[i].pop_back();
		// }
		todo += SZ(g[i]);
	}
	kt.resize(n);
	FOR(s, n){
		FOR(i, n) kt[i] = SZ(g[i])-1;
		int td = todo;
		int cnt = 0;
		int mxwait = 0;
		int ps = s;
		while(td > 0 || mxwait > 0){
			if(kt[ps] >= 0){
				mxwait = std::max(mxwait, g[ps][kt[ps]]-ps+(g[ps][kt[ps]]<ps ? n : 0));
				kt[ps]--;
				td--;
			}
			ps = (ps+1)%n;
			mxwait = std::max(0, mxwait-1);
			cnt++;
		}
		std::cout << cnt << " ";
	}
	return 0;
}