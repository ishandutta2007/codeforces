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

ll ans = 0;
int n;
int A[300005];
int cnt[2][2000000];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	cnt[1][0]++;
	int pref = 0;
	FOR(i, n){
		std::cin >> A[i];
		pref = pref ^ A[i];
		ans += cnt[i%2][pref];
		cnt[i%2][pref]++;
		// std::cout << pref << "\n";
	}
	std::cout << ans;
	return 0;
}