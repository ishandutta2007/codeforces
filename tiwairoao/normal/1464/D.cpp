#include <bits/stdc++.h>

const int N = 1000000;
const int P = int(1E9) + 7;

int pow3(int x) {
	int r = 1; for(int i=1;i<=x;i++) r = (int)(3ll * r % P);
	return r;
}

bool vis[N + 5]; int p[N + 5], n;

int cnt[3];
void solve() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &p[i]), vis[i] = false;
	if( n % 3 == 0 ) printf("%d ", pow3(n / 3));
	else if( n % 3 == 1 ) printf("%lld ", 4ll * pow3(n / 3 - 1) % P);
	else printf("%lld ", 2ll * pow3(n / 3) % P);
	
	if( n % 3 == 0 ) {
		int ans = 0; cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i=1;i<=n;i++) {
			if( vis[i] ) continue;
			int x = i, s = 0;
			do {
				vis[x] = true, x = p[x], s++;
			}while( !vis[x] );
			ans += (s / 3), cnt[s % 3]++;
		}
		ans -= cnt[0];
		int d = std::min(cnt[1], cnt[2]);
		ans += d, cnt[1] -= d, cnt[2] -= d;
		printf("%d\n", ans + cnt[1] / 3 * 2 + cnt[2]);
	} else if( n % 3 == 1 ) {
		int ans = 0; cnt[0] = cnt[1] = cnt[2] = 0; bool flag = false;
		for(int i=1;i<=n;i++) {
			if( vis[i] ) continue;
			int x = i, s = 0;
			do {
				vis[x] = true, x = p[x], s++;
			}while( !vis[x] );
			ans += (s / 3), cnt[s % 3]++;
			if( s % 3 == 1 && s >= 3 ) flag = true;
		}
		ans -= cnt[0];
		
		int res = (1 << 30);
		if( flag ) {
			cnt[1]--, ans--;
			int d = std::min(cnt[1], cnt[2]);	
			res = std::min(res, ans + d + (cnt[1] - d) / 3 * 2 + (cnt[2] - d));
			cnt[1]++, ans++;
		}
		
		int d = std::min(cnt[1], cnt[2]);
		if( cnt[1] - d ) {
			if( cnt[1] - d == 1 )
				res = std::min(res, ans + d + 1);
			else res = std::min(res, ans + d + (cnt[1] - d - 4) / 3 * 2 + 2);
		}
		else res = std::min(res, ans + d + (cnt[2] - d - 2));
		
		if( cnt[1] >= 2 ) {
			ans++, cnt[1] -= 2, cnt[2]++;
			d = std::min(cnt[1], cnt[2]);
			if( cnt[1] - d ) {
				if( cnt[1] - d == 1 )
					res = std::min(res, ans + d + 1);
				else res = std::min(res, ans + d + (cnt[1] - d - 4) / 3 * 2 + 2);
			} else res = std::min(res, ans + d + (cnt[2] - d - 2));
			ans--, cnt[1] += 2, cnt[2]--;
		}
		
		printf("%d\n", res);
	} else {
		int ans = 0; cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i=1;i<=n;i++) {
			if( vis[i] ) continue;
			int x = i, s = 0;
			do {
				vis[x] = true, x = p[x], s++;
			}while( !vis[x] );
			ans += (s / 3), cnt[s % 3]++;
		}
		ans -= cnt[0];
		int d = std::min(cnt[1], cnt[2]);
		ans += d, cnt[1] -= d, cnt[2] -= d;
		if( cnt[1] ) printf("%d\n", ans + (cnt[1] - 2) / 3 * 2 + 1);
		else printf("%d\n", ans + (cnt[2] - 1));
	}
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}