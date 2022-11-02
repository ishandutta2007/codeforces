#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int N = 612345;

ll sum[2][N << 2];
int tr[2][N << 2], v[2][N];

void build(int o, int i, int l, int r) {
	sum[o][i] = 0;
	if(l == r) return (void) (tr[o][i] = v[o][l]);
	int m = (l + r) / 2;
	build(o, 2 * i, l, m);
	build(o, 2 * i + 1, m + 1, r);
	tr[o][i] = max(tr[o][2 * i], tr[o][2 * i + 1]);
}

#define set set_

void set(int o, int i, int l, int r, int p, ll x) {
	if(l == r) return (void) (sum[o][i] = x);
	int m = (l + r) / 2;
	if(p <= m) set(o, 2 * i, l, m, p, x);
	else set(o, 2 * i + 1, m + 1, r, p, x);
	sum[o][i] = mod(sum[o][2 * i] + sum[o][2 * i + 1]);
}

#define mp make_pair

ll get(int o, int i, int l, int r, int ql) {
	if(tr[o][i] < ql) return sum[o][i];
	if(l == r) return 0;
	int m = (l + r) / 2;
	ll g = get(o, 2 * i, l, m, ql);
	if(tr[o][2 * i] < ql) g = mod(g + get(o, 2 * i + 1, m + 1, r, ql));
	return g;
}

int c[N], cn;

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

ll dp[N][3]; // p = 2 -> mixed

int l[2][N], r[2][N];

int main() {
	int k, n[2], i, j;
	scanf("%d %d %d", &k, &n[0], &n[1]);
	for(j = 0; j < 2; j++)
		for(i = 0; i < n[j]; i++) {
			scanf("%d %d", &l[j][i], &r[j][i]);
			c[cn++] = l[j][i];
			c[cn++] = r[j][i];
			if(r[j][i] != k) c[cn++] = r[j][i] + 1;
		}
	c[cn++] = 1;
	c[cn++] = k;
	sort(c, c + cn);
	cn = unique(c, c + cn) - c;
	for(i = 0; i < cn; i++)
		v[0][i] = v[1][i] = -1;
	for(j = 0; j < 2; j++)
		for(i = 0; i < n[j]; i++) {
			l[j][i] = lower_bound(c, c + cn, l[j][i]) - c;
			r[j][i] = lower_bound(c, c + cn, r[j][i]) - c;
			v[j][r[j][i]] = max(v[j][r[j][i]], l[j][i]);
		}
	//for(j = 0; j < 2; j++)
	//	for(i = 0; i < cn; i++)
	//		printf("v[%d][%d] = %d\n", j, i, v[j][i]);
	build(0, 1, 0, cn - 1);
	build(1, 1, 0, cn - 1);
	dp[cn][0] = dp[cn][1] = dp[cn][2] = 1;
	set(1, 1, 0, cn - 1, cn - 1, 1);
	set(0, 1, 0, cn - 1, cn - 1, 1);
	for(i = cn - 1; i >= 0; i--) {
		for(int p = 0; p < 3; p++) {
			ll &r = dp[i][p];
			if(v[0][i] == i && v[1][i] == i) continue; // 0 possibilites
			if(i != cn - 1 && c[i + 1] - c[i] > 1) {
				ll qt;
				qt = mod(fexp(2, c[i + 1] - c[i]) - 2 + modn);
				r = mod(dp[i + 1][2] * qt);
			}
			if(p != 0) // put 0
				r = mod(r + get(1, 1, 0, cn - 1, i)); // 1-restrictions may be messed up
			if(p != 1) // put 1
				r = mod(r + get(0, 1, 0, cn - 1, i));
			//printf("dp[%d][%d] = %lld\n", i, p, r);
		}
		if(i) {
			set(1, 1, 0, cn - 1, i - 1, dp[i][0]);
			set(0, 1, 0, cn - 1, i - 1, dp[i][1]);
		}
	}
	printf("%lld\n", dp[0][2]);
}