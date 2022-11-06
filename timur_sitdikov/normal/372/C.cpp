#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int MAXN = 150005;

long long dp[2][20][2 * MAXN];
int sz[2 * MAXN], st2[2 * MAXN];

void solve(){
	long long d, b, a, t, tlast, len, lim, ll, rr;
	int n, i, j, k, lg_i, lg_next, ind, m, l, r;
	scanf("%d%d%I64d", &n, &m, &d);
	for(lg_i = 0, i = 1; i <= n; lg_i++, i *= 2){
		st2[lg_i] = i;
		for(j = i; j < 2 * i; j++){
			if (j > n){
				break;
			}
			sz[j] = lg_i;
		}
	}
	tlast = 0;
	for(j = 0; j < m; j++){
		scanf("%I64d%I64d%I64d", &a, &b, &t);
		len = d * (t - tlast);
		tlast = t;
		ind = j & 1;
		for(lg_i = 0, k = 1; k < n; lg_i++, k *= 2){
			lim = n - k + 1;
			lg_next = lg_i + 1;
			for(i = 1; i <= lim; i++){
				dp[ind][lg_next][i] = dp[ind][lg_i][i];
			}
			for(i = k + 1; i <= n; i++){
				if (dp[ind][lg_next][i - k] < dp[ind][lg_i][i]){
					dp[ind][lg_next][i - k] = dp[ind][lg_i][i];
				}
			}
		}
		for(i = 1; i <= n; i++){
			ll = max(1ll, i - len);
			l = ll;
			rr = min(n * 1ll, i + len);
			r = rr;
			lg_i = sz[r - l + 1];
			dp[ind ^ 1][0][i] = max(dp[ind][lg_i][l], dp[ind][lg_i][r - st2[lg_i] + 1]);
			dp[ind ^ 1][0][i] += b - abs(a - i);
		}
	}
	long long ans = dp[m & 1][0][1];
	for(i = 1; i <= n; i++){
		ans = max(ans, dp[m & 1][0][i]);
	}
	printf("%I64d", ans);
}

int main(){	
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	t = 1;
	while(t){
		t--;
		solve();
	}
}