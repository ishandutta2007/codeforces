#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 251
#define LL long long
#define mp make_pair
#define pb push_back
#define M 1000000007
#define pow qjwopjqpw

int dp[K][K][4][4];
pair<int, int> nxt[K][K][4][4];

vector<pair<int, int> > ret;

int solve2(int s1, int s2, int g1, int g2) {
	if (g1 == 0 && g2 == 0) {
		return (s1 == 0 && s2 == 0 ? 1: 0);	
	}
	
	if (s1 == 0 && s2 == 0) return 0;
	
	if (dp[s1][s2][g1][g2] == -1) {
		dp[s1][s2][g1][g2] = 0;
		
		int ma = (max(g1, g2) == 3 && min(g1, g2) == 2 ? 15 : 25);
		
		// first player win
		if (g2 != 3 && g1 > 0) {
			FOE(i, ma, s1) if (dp[s1][s2][g1][g2] == 0) {
				int low = 0, high = min(s2, i - 2);
				
				if (i != ma) low = i - 2;
				
				FOE(j, low, high) {
					int val = solve2(s1 - i, s2 - j, g1 - 1, g2);
					
					if (val) {
						dp[s1][s2][g1][g2] = 1;
						nxt[s1][s2][g1][g2] = mp(i, j);
						break;
					}
				}
			}
		}
		
		if (dp[s1][s2][g1][g2] == 0 && g1 != 3 && g2 > 0) {
			FOE(i, ma, s2) if (dp[s1][s2][g1][g2] == 0) {
				int low = 0, high = min(s1, i - 2);
				
				if (i != ma) low = i - 2;
				
				FOE(j, low, high) {
					int val = solve2(s1 - j, s2 - i, g1, g2 - 1);
					
					if (val) {
						dp[s1][s2][g1][g2] = 1;
						nxt[s1][s2][g1][g2] = mp(j, i);
						break;
					}
				}
			}
			
		}
	}
	
	return dp[s1][s2][g1][g2];
}

int a, b;

void trace(int s1, int s2, int g1, int g2) {
	if (g1 == 0 && g2 == 0) return;
	auto w = nxt[s1][s2][g1][g2];
	
	ret.pb(w);
	
	if (w.first > w.second) {
		trace(s1 - w.first, s2 - w.second, g1 - 1, g2);	
	} else {
		trace(s1 - w.first, s2 - w.second, g1, g2 - 1);	
	}
}
 
void solve() {
	scanf("%d%d", &a, &b);
	ret.clear();
	
	FOE(i, 0, 2) if (solve2(a, b, 3, i) == 1) {
		printf("3:%d\n", i);
		trace(a, b, 3, i);	
		FOD(i, (int)(ret.size()) - 1, 0) printf("%d:%d%c", ret[i].first, ret[i].second, (i == 0 ? '\n' : ' '));
		return;	
	}
	
	FOD(i, 2, 0) if (solve2(a, b, i, 3) == 1) {
		printf("%d:3\n", i);
		trace(a, b, i, 3);
		FOD(i, (int)(ret.size()) - 1, 0) printf("%d:%d%c", ret[i].first, ret[i].second, (i == 0 ? '\n' : ' '));
		return;	
	}
	
	puts("Impossible");
}
 
int main() {
	int t;
	scanf("%d", &t);
	
	FOE(i, 0, 200) FOE(j, 0, 200) FOE(l, 0, 3) FOE(p, 0, 3) dp[i][j][l][p] = -1;
	while (t--) solve();
}