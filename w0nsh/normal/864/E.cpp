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

int n, dp[105][2005];
PII back[105][2005];
std::vector<PR<int, PR<PII, int> > > items;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a, b, c;
		std::cin >> a >> b >> c;
		items.push_back(MP(b, MP(MP(a, c), i)));
	}
	std::sort(items.begin(), items.end());
	REP(i, 1, n+1){
		auto cur = items[i-1];
		REP(s, cur.Y.X.X, cur.X){
			int last = s-cur.Y.X.X;
			FOR(j, i){
				if(dp[i][s] < dp[j][last] + cur.Y.X.Y){
					dp[i][s] = dp[j][last] + cur.Y.X.Y;
					back[i][s] = MP(j, last);
				}
			}
		}
	}
	PII max = MP(0, 0);
	REP(i, 1, n+1) REP(s, 0, 2005) if(dp[i][s] > dp[max.X][max.Y]) max = MP(i, s);
	int mx = dp[max.X][max.Y];
	VI ans;
	while(max.X > 0){
		ans.push_back(max.X);
		max = back[max.X][max.Y];
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << mx << "\n" << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << items[i-1].Y.Y+1 << " ";
	return 0;
}