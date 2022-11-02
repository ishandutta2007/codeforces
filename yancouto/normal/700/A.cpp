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
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, k;
double v1, v2, l;

double ans;
double solve(double x) {
	double t = x / v2;
	for(int i = k; i < n; i += k) {
		double f = v1 * t;
		double t1 = (x - f) / (v1 + v2);
		double y = f + v1 * t1;
		double z = x + v1 * t1;
		double t2 = (z - y) / (v2 - v1);
		t += t1 + t2;
		x = z + v1 * t2;
	}
	ans = t;
	if(x > l) return false;
	return true;
}

int main() {
	int i, j;
	scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);
	if(k == n) { printf("%.10f\n", l / v2); return 0; }
	double le = 0, ri = 1e9;
	while(le < ri && clock() < .9 * CLOCKS_PER_SEC) {
		double m = (le + ri) / 2;
		if(solve(m)) le = m;
		else ri = m;
	}
	solve(le);
	printf("%.10f\n", ans);
}