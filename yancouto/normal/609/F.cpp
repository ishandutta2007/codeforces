#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 400009;
ll tr[N << 2];
inline int L(int i) { return i << 1; }
inline int R(int i) { return L(i) + 1; }

ll x[N], y[N]; int eat[N];

void upd(int i, int l, int r, int x, int val) {
	if(l == r) return void(tr[i] = val);
	int m = (l + r) / 2;
	if(x <= m) upd(L(i), l, m, x, val);
	else upd(R(i), m + 1, r, x, val);
	tr[i] = max(tr[L(i)], tr[R(i)]);
}

int collect_one(int i, int l, int r, int xl, int xr, int yl) {
	if(l > xr || r < xl) return -1;
	int m = (l + r) / 2;
	if(l >= xl && r <= xr) {
		if(tr[i] < yl) return -1;
		if(l == r) return l;
		if(tr[L(i)] >= yl) return collect_one(L(i), l, m, xl, xr, yl);
		else return collect_one(R(i), m + 1, r, xl, xr, yl);
	}
	int ret = collect_one(L(i), l, m, xl, xr, yl);
	if(ret != -1) return ret;
	return collect_one(R(i), m + 1, r, xl, xr, yl);
}

int cn;
int p[N], b[N], c[N], inv[N];
int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]); y[i] += x[i];
		c[i] = x[i];
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &p[i], &b[i]);
		c[i + n] = p[i];
	}
	sort(c, c + n + m);
	cn = unique(c, c + n + m) - c;
	for(i = 0; i < cn; i++) upd(1, 0, cn - 1, i, -1);
	for(i = 0; i < n; i++) {
		x[i] = lower_bound(c, c + cn, x[i]) - c;
		inv[x[i]] = i;
		upd(1, 0, cn - 1, x[i], y[i]);
	}
	multimap<int, int> mos;
	for(i = 0; i < m; i++) {
		int comp = lower_bound(c, c + cn, p[i]) - c;
		j = collect_one(1, 0, cn - 1, 0, comp, p[i]);
		if(j == -1) { mos.insert(make_pair(p[i], b[i])); continue; }
		j = inv[j];
		y[j] += b[i];
		eat[j]++;
		auto it = mos.lower_bound(c[x[j]]);
		while(it != mos.end() && it->fst <= y[j]) {
			y[j] += it->snd;
			eat[j]++;
			it = mos.erase(it);
		}
		upd(1, 0, cn - 1, x[j], y[j]);
	}
	for(i = 0; i < n; i++)
		printf("%d %I64d\n", eat[i], y[i] - ll(c[x[i]]));
}