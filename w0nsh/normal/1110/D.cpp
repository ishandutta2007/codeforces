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

int n, m, cnt[1000005], dp[1000005][3][3];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n){
		int a;
		std::cin >> a;
		cnt[a]++;
	}
	REP(i, 1, m+1) FOR(a, 3) FOR(b, 3) FOR(cur, 3){
		if(i <= 2 && a > 0) continue;
		if(i == 1 && b > 0) continue;
		if(a != 0 && a > cnt[i-2]) continue;
		if(a + b != 0 && a + b > cnt[i-1]) continue;
		if(a + b + cur > cnt[i]) continue;
		dp[i][b][cur] = std::max(dp[i][b][cur], dp[i-1][a][b] + cur + (cnt[i]-cur-a-b)/3);
	}
	std::cout << dp[m][0][0] << "\n";
	return 0;
}