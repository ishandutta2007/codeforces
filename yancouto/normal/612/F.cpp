#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 2009;
int a[N], b[N], bn, n;
vector<int> oc[N];

int mn_dist(int a, int b) {
	return min(abs(a - b), n - abs(a - b));
}

int solve(int);

int solve_aux(int i, int val) {
	const int on = oc[val].size();
	if(on == 1) {
		return mn_dist(i, oc[val].front()) + solve(oc[val].front());
	}
	int R = INT_MAX;
	for(int j = 0; j < on; j++) {
		int l = oc[val][(j + on - 1) % on], r = oc[val][(j + 1) % on];
		int cur = oc[val][j];
		int dis = l - r;
		if(dis < 0) dis += n;
		R = min(R, dis + mn_dist(i, l) + mn_dist(r, cur) + solve(cur));
		R = min(R, dis + mn_dist(i, r) + mn_dist(l, cur) + solve(cur));
		if(on == 3) {
			R = min(R, mn_dist(i, l) + mn_dist(l, cur) + 2 * mn_dist(r, cur) + solve(cur));
			R = min(R, mn_dist(i, r) + mn_dist(r, cur) + 2 * mn_dist(l, cur) + solve(cur));
		}
	}
	return R;
}

int memo[N];
int solve(int i) {
	int &r = memo[i];
	if(r != -1) return r;
	if(a[i] == bn - 1) return 0;
	r = solve_aux(i, a[i] + 1);
	return r;
}

int int_dist(int a, int b) {
	int d = mn_dist(a, b);
	if(((a + d) % n) == b) return d;
	else return -d;
}

void prn(int x) {
	if(x >= 0) printf("+%d\n", x);
	else printf("%d\n", x);
}

void deb_dist(int a, int b) {
	prn(int_dist(a, b));
}

void build(int);

void build_aux(int i, int val, int ans) {
	const int on = oc[val].size();
	if(on == 1) {
		deb_dist(i, oc[val].front());
		build(oc[val].front());
		return;
	}
	for(int j = 0; j < on; j++) {
		int aj = (j + on - 1) % on;
		int nj = (j + 1) % on;
		swap(nj, aj);
		int l = oc[val][(j + on - 1) % on], r = oc[val][(j + 1) % on];
		int cur = oc[val][j];
		int dis = l - r;
		if(dis < 0) dis += n;
		if(on == 3) {
			if(ans == mn_dist(i, l) + mn_dist(l, cur) + 2 * mn_dist(r, cur) + solve(cur)) {
				deb_dist(i, l);
				deb_dist(l, r);
				deb_dist(r, cur);
				build(cur);
				return;
			}
			if(ans == mn_dist(i, r) + mn_dist(r, cur) + 2 * mn_dist(l, cur) + solve(cur)) {
				deb_dist(i, r);
				deb_dist(r, l);
				deb_dist(l, cur);
				build(cur);
				return;
			}
		}
		if(ans == dis + mn_dist(i, l) + mn_dist(r, cur) + solve(cur)) {
			deb_dist(i, l);
			for(int k = nj; k != aj; k = (k - 1 + on) % on) {
				int d = oc[val][k] - oc[val][(k - 1 + on) % on];
				if(d < 0) d += n;
				printf("-%d\n", d);
			}
			deb_dist(r, cur);
			build(cur);
			return;
		}
		if(ans == dis + mn_dist(i, r) + mn_dist(l, cur) + solve(cur)) {
			deb_dist(i, r);
			for(int k = aj; k != nj; k = (k + 1) % on) {
				int d = oc[val][(k + 1) % on] - oc[val][k];
				if(d < 0) d += n;
				printf("+%d\n", d);
			}
			deb_dist(l, cur);
			build(cur);
			return;
		}
	}
}

void build(int i) {
	if(a[i] == bn - 1) return;
	build_aux(i, a[i] + 1, solve(i));
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, s;
	scanf("%d %d", &n, &s); s--;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	bn = unique(b, b + n) - b;
	for(i = 0; i < n; i++) {
		a[i] = lower_bound(b, b + bn, a[i]) - b;
		oc[a[i]].pb(i);
	}
	int r = solve_aux(s, 0);
	printf("%d\n", r);
	build_aux(s, 0, r);
}