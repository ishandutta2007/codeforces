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
VI p;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	p.resize(n);
	FOR(i, n) std::cin >> p[i], p[i]--;
	FOR(_, m){
		int l, r, x;
		std::cin >> l >> r >> x;
		l--;r--;x--;
		int cnt = 0;
		REP(i, l, x) if(p[i] > p[x]) cnt++;
		REP(i, x+1, r+1) if(p[i] < p[x]) cnt--;
		if(cnt == 0) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
	return 0;
}