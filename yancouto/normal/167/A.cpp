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

int t[112345]; double v[112345];
int main() {
	int i, j, n;
	double a, d;
	scanf("%d %lf %lf", &n, &a, &d);
	double mx = -1./0.;
	for(i = 0; i < n; i++) {
		scanf("%d %lf", &t[i], &v[i]);
		double dist = v[i] * v[i] / (2. * a);
		double tim = t[i];
		if(dist > d) {
			tim += sqrt((2.*d) / a);
		} else {
			tim += v[i] / a;
			tim += (d - dist) / v[i];
		}
		if(tim < mx) tim = mx;
		mx = tim;
		printf("%.10lf\n", tim);
	}
}