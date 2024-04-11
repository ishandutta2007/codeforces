/*
 * Author       : YangDavid
 * Created Time : 20191201  154332
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

const int maxn = 2433;

ll fac[23], cnt[23], pre[23];
void solve() {
	memset(cnt, 0, sizeof cnt);
	memset(pre, 0, sizeof pre);
	ll x, xcpy, ans = 1, level = 2;
	scanf("%llu", &x); xcpy = x;

	for(int i = 2; x; ++i) {
		cnt[x % i]++;
		x /= i;
		level = i;
	}
	pre[0] = cnt[0];
	for(int i = 1; i <= level; ++i)
		pre[i] += pre[i - 1] + cnt[i];
	for(int i = 2; i <= level; ++i) {
		ans = ans * (pre[i - 1] - i + 2);
	}
	ll sub = cnt[0];
	if(cnt[0]) {
		for(int i = 2; i < level; ++i) {
			sub = sub * (pre[i-1] - i + 1);
			if(pre[i-1]-i+1 <= 0) sub = 0;
		}
		ans -= sub;
	}
	for(int i = 0; i <= level; ++i)
		ans /= fac[cnt[i]];
	printf("%llu\n", ans - 1);
}

int main() {
	fac[0] = 1;
	for(int i = 1; i <= 22; ++i)
		fac[i] = fac[i - 1] * i;

	int T; scanf("%d", &T);
	while(T--) solve();

    return 0;
}