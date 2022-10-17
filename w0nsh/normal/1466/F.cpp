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

constexpr int MOD = 1000000007;


VI repr;
int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}
void Union(int a, int b){
	repr[Find(a)] = Find(b);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	repr.resize(m+1);
	FOR(i, m+1) repr[i] = i;
	int ans = 1;
	VI vec;
	FOR(i, n){
		int k;
		std::cin >> k;
		if(k == 2){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			int x = Find(a);
			int y = Find(b);
			if(x != y){
				vec.push_back(i+1);
				Union(std::min(x, y), std::max(x, y));
				ans = (ans+ans)%MOD;
			}
		}
		else{
			int a;
			std::cin >> a;
			a--;
			a = Find(a);
			if(a < m){
				ans = (ans+ans)%MOD;
				Union(a, m);
				vec.push_back(i+1);
			}
		}
	}

	std::cout << ans << " " << SZ(vec) << "\n";
	TRAV(i, vec) std::cout << i << " ";

	return 0;
}