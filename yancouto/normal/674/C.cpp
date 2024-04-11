#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 212345;
int t[N], n;
ll sum[N];
double inv[N], all[N];

inline ll S(int i, int j) {
	return sum[j] - (i? sum[i - 1] : 0ll);
}

inline double I(int i, int j) {
	return inv[j] - (i? inv[i - 1] : 0.);
}

inline double A(int i, int j) {
	return all[j] - (i? all[i - 1] : 0.);
}

double v(int i, int j) {
	double tot = A(i, j);
	tot = tot - (i? S(0, i-1) : 0) * I(i, j);
	return tot;
}

double pd[53][200009];
double get(int k, int i) {
	if(i == n) return 0;
	if(k == 0) return 1/0.;
	return pd[k][i];
}

void rec(int k, int l, int r, int ql, int qr) {
	if(r < l) return;
	int m = (l + r) / 2;
	pd[k][m] = 1/0.;
	int bi;
	for(int i = max(m, ql); i <= qr; i++) {
		double ans = get(k - 1, i + 1) + v(m, i);
		if(ans < pd[k][m]) {
			pd[k][m] = ans;
			bi = i;
		}
	}
	rec(k, l, m - 1, ql, bi);
	rec(k, m + 1, r, bi, qr);
}

void solve(int k) {
	rec(k, 0, n - 1, 0, n - 1);
}

int main(int argn, char **args) {
	int i, j, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &t[i]);
	sum[0] = t[0];
	for(i = 1; i < n; i++)
		sum[i] = sum[i - 1] + ll(t[i]);
	inv[0] = 1. / double(t[0]);
	for(i = 1; i < n; i++)
		inv[i] = inv[i - 1] + 1. / double(t[i]);
	all[0] = 1;
	for(i = 1; i < n; i++)
		all[i] = all[i - 1] + double(sum[i]) / t[i];
	for(i = 1; i <= k; i++)
		solve(i);
	double a = pd[k][0];
	printf("%.10f\n", a);
}