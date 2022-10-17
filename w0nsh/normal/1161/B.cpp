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

constexpr int MOD = 1000000007;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::map<VI, int> map;
	int n, m;
	std::cin >> n >> m;
	std::vector<VI> vec(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(b > a){
			vec[a].push_back(b-a);
			vec[b].push_back(a-b+n);
		}else{
			vec[a].push_back(b-a+n);
			vec[b].push_back(a-b);
		}
	}
	VI word;
	FOR(i, n){
		std::sort(vec[i].begin(), vec[i].end());
		if(map.find(vec[i]) == map.end()) map[vec[i]] = SZ(map);
		word.push_back(map[vec[i]]);
	}
	int b[2];
	b[0] = SZ(map)+5;
	b[1] = SZ(map)+117;
	VI pw[2];
	FOR(i, 2){
		pw[i].push_back(1);
		FOR(j, n) pw[i].push_back((1ll*pw[i].back()*b[i])%MOD);
	}
	int h[2];
	h[0] = h[1] = 0;
	std::set<int> hsh[2];
	FOR(k, 2){
		FOR(i, n){
			h[k] = (1ll*h[k] + 1ll*pw[k][i]*word[i])%MOD;
		}
		hsh[k].insert(h[k]);
	}
	for(int i = n-1; i >= 1; --i){
		int bad = 0;
		FOR(k, 2){
			h[k] = (1ll*h[k] - 1ll*pw[k][n-1]*word[i])%MOD;
			h[k] = (1ll*h[k]*b[k] + 1ll*word[i])%MOD;
			if(h[k] < 0) h[k] += MOD;			
			if(hsh[k].count(h[k])) bad++;
			hsh[k].insert(h[k]);
		}
		if(bad == 2){
			std::cout << "Yes\n";
			return 0;
		}
	}
	std::cout << "No\n";

	return 0;
}