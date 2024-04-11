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


int n, pref[2][200005];
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	FOR(j, 2) FOR(i, n) pref[j][i+1] = pref[j][i] + (i%2 == j ? A[i] : 0);
	int ans = 0;
	FOR(i, n){
		int even = pref[0][i] + pref[1][n]-pref[1][i+1];
		int odd = pref[1][i] + pref[0][n]-pref[0][i+1];
		if(even == odd) ans++;
	}
	std::cout << ans;
	return 0;
}