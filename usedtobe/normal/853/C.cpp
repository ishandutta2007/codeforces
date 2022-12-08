#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 6666666, N = 222222;
ll C(int x) {return 1ll * x * (x - 1) / 2;}
int tot, lc[M], rc[M], sum[M];
int a[N];
void add(int &cur, int pre, int l, int r, int p) {
	cur = ++tot;
	lc[cur] = lc[pre];
	rc[cur] = rc[pre];
	sum[cur] = sum[pre] + 1;
	if (l == r) return;
	int md = (l + r) >> 1;	
	if (p <= md) add(lc[cur], lc[pre], l, md, p);
	else add(rc[cur], rc[pre], md + 1, r, p);
}
int ask(int cur, int l, int r, int L, int R) {
	if (!cur) return 0;
	//cout << l << " " << r << " " << L << " " << R << endl;
	if (L <= l && R >= r) return sum[cur];
	int ans = 0, md = (l + r) >> 1;
	if (L <= md) ans += ask(lc[cur], l, md, L, R); 
	if (R > md) ans += ask(rc[cur], md + 1, r, L, R);
	return ans;
}
int rt[N], n, Q;
int get(int l, int r, int d, int u) { 
	if (l > r || d > u) return 0;
	return ask(rt[r], 1, n, d, u) - ask(rt[l - 1], 1, n, d, u); 
}
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) add(rt[i], rt[i - 1], 1, n, a[i]);
	while (Q--) {
		int l, r, d, u;
		scanf("%d%d%d%d", &l, &d, &r, &u);
		ll ans = C(l - 1) + C(n - u) + C(n - r) + C(d - 1);
		ans -= C(get(1, l - 1, 1 , d - 1));
		ans -= C(get(1, l - 1, u + 1 , n));
		ans -= C(get(r + 1, n, 1 , d - 1));
		ans -= C(get(r + 1, n, u + 1, n));
		printf("%I64d\n", C(n) - ans);
	}
	return 0;
}