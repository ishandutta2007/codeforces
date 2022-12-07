#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 64
#define offset 64
#define inf 2000000020
using namespace std;

int floor(int x, int y) {
	if (x >= 0) return x / y;
	x = -x;
	return -((x - 1) / y + 1); //XXX
}
int n, num[maxn];
char s[maxn];
/*
int dp[maxn][offset << 1][maxn * 5][maxn * 5];
bool vis[maxn][offset << 1][maxn * 5][maxn * 5];
int DP(int pos, int car, int cp, int cn) {
	if (pos >= n) {
		if (pos == maxn) return inf;
		if (car == offset && !cp && !cn) return 0;
	}
	if (vis[pos][car][cp][cn]) return dp[pos][car][cp][cn];
	vis[pos][car][cp][cn] = 1;
	int& ans = dp[pos][car][cp][cn];
	ans = inf;
	if (cp) ans = min(ans, DP(pos, car, cp - 1, cn));
	if (cn) ans = min(ans, DP(pos, car, cp, cn - 1));
	car -= offset;
	if ((car + cp - cn % 10 + 10) % 10 != num[pos]) return ans;
	int _car = floor(car + cp - cn, 10) + offset;
	int dd = DP(pos + 1, _car, cp, cn);
	if (dd != inf) ans = min(ans, dd + cp + cn); 
	return ans;
}
*/

#define DP(pos, car, cp, cn) dp[pos][car][cp][cn]
int dp[2][offset << 1][maxn * 5][maxn * 5];
int solve(){	//XXX
	int d = 0;
	per(pos, maxn, 0) {
		d ^= 1;
		srep(car, 0, offset << 1) {
			rep(cp, 0, 5 * n) {
				rep(cn, 0, 5 * n) {
					int& ans = dp[d][car][cp][cn];
					if (pos >= n) {
						if (pos == maxn) {ans = inf; continue;} //XXX
						if (car == offset && !cp && !cn) {ans = 0; continue;}
					}
					//if (vis[pos][car][cp][cn]) return dp[pos][car][cp][cn];
					//vis[pos][car][cp][cn] = 1; //XXX 
					ans = inf;
					if (cp) ans = min(ans, DP(d, car, cp - 1, cn));
					if (cn) ans = min(ans, DP(d, car, cp, cn - 1));
					int __car = car - offset;
					if ((10 + __car % 10 + cp - cn % 10 + 10) % 10 != num[pos]) continue;
					int _car = floor(__car + cp - cn, 10) + offset;
					if (0 <= _car && _car < (offset << 1)) {
						int dd = DP(d ^ 1, _car, cp, cn);
						if (dd != inf) ans = min(ans, dd + cp + cn); 
					} 
					//return ans;
				}
			}
		}
	}
	return d;
}
int main(){
	scanf("%s", s);
	n = strlen(s);
	srep(i, 0, n) num[i] = s[n - i - 1] - '0';
	int d = solve();
	int res = inf;
	rep(cp, 0, 5 * n) {
		rep(cn, 0, 5 * n) {
			res = min(res, DP(d, offset, cp, cn)); 
		}
	}
	cout << res << endl;
	
	//cerr << floor(-2, 10) << endl;
	return 0;
}