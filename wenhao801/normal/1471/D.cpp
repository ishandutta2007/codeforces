#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define ull unsigned long long
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}
#define ll long long
const int LIM = 1000000, MAXN = LIM + 100;
int p[MAXN], top; bool np[MAXN];
void genp () {
	int i, j;
	for (i = 2; i <= LIM; i++ ) {
		if (!np[i]) p[++top] = i;
		for (j = 1; j <= top; j++) {
			if (i * p[j] > LIM) break;
			np[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
map <ull, int> mp;
struct num { int r; bool t[169]; } b[MAXN];
ull Hash (int x) {
	ull ret = 0;
	for (int i = 1; i <= 168; i++) ret = ret * ((ull)1009) + b[x].t[i] * p[i];
	ret = ret * ((ull)(998244353)) + ((ull)b[x].r);
	return ret;
}
ull a[300300];

int main () {
	genp(); int i, j;
	for (i = 1; i <= LIM; i++) {
		int x = i;
		for (j = 1; j <= 168 && x != 1; j++) {
			while (x % p[j] == 0) x /= p[j], b[i].t[j] ^= 1;
		}
		b[i].r = x;
	}
	int T = read();
	while (T--) {
		mp.clear();
		int n = read();
		for (i = 1; i <= n; i++) {
			int x = read();
			a[i] = Hash(x);
			++mp[a[i]];
		}
		sort(a + 1, a + n + 1); int m = unique(a + 1, a + n + 1) - a - 1;
		int cnt[2] = {}, cnt1 = 0, ans0 = 0, ans1 = 0;
		for (i = 1; i <= m; i++) {
			int rua = mp[a[i]];
			if (a[i] == 1) { cnt1 = rua; continue; }
			cnt[rua & 1] += rua;
			if (rua & 1) ans1 = max(ans1, rua);
			ans0 = max(ans0, rua);
		}
		ans0 = max(ans0, cnt1);
		ans1 = max(ans1, cnt1 + cnt[0]);
		int q = read();
		while (q--) {
			ll w; scanf("%lld", &w);
			if (w == 0) printf("%d\n", ans0);
			else printf("%d\n", ans1);
		}
	}
	return 0;
}