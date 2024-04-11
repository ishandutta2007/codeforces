#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

const int MOD = 998244353;
int n, m, count[200005], pref[200005], pw[200005];
std::string A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	pw[0] = 1;
	FOR(i, 200003) pw[i+1] = (pw[i]*2)%MOD;
	std::cin >> n >> m >> A;
	FOR(i, m){
		char ch;
		std::cin >> ch;
		pref[i+1] = pref[i] + (ch == '1' ? 1 : 0);
	}
	int ans = 0;
	FOR(i, n){
		if(m-i > 0 && A[n-1-i] == '1') ans = (1ll*pref[m-i]*pw[i]+ans)%MOD;
	}
	std::cout  << ans << "\n";
	return 0;
}