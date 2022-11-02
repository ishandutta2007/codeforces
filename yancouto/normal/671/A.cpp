#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<long double, int> pii;
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

#define temp template<typename num>
#define ptn point<num>
temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x * o.x + y * o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	ptn operator * (num i) const { return ptn(x * i, y * i); }
	ptn operator / (num i) const { return ptn(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num dist_sqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<ll> pti;

pti a, b, t;
pti p[112345]; 
long double dt[112345];

int main() {
	int i, n;
	scanf(LLD LLD LLD LLD LLD LLD, &a.x, &a.y, &b.x, &b.y, &t.x, &t.y);
	scanf("%d", &n);
	vector<pii> ad, bd;
	long double all = 0;
	for(i = 0; i < n; i++) {
		scanf(LLD LLD, &p[i].x, &p[i].y);
		dt[i] = real(sqrt<long double>(p[i].dist_sqr(t)));
		all += dt[i] + dt[i];
		ad.pb(pii(dt[i] - real(sqrt<long double>(a.dist_sqr(p[i]))), i));
		bd.pb(pii(dt[i] - real(sqrt<long double>(p[i].dist_sqr(b))), i));
	}
	sort(ad.begin(), ad.end(), greater<pii>());
	sort(bd.begin(), bd.end(), greater<pii>());
	long double best = 1/0.;
	best = min(best, all - ad[0].fst);
	debug("solA %Lf\n", best);
	best = min(best, all - bd[0].fst);
	debug("min=solB %Lf\n", best);
	if(ad[0].snd != bd[0].snd)
		best = min(best, all - ad[0].fst - bd[0].fst);
	else if(n > 1) {
		best = min(best, all - ad[0].fst - bd[1].fst);
		best = min(best, all - ad[1].fst - bd[0].fst);
	}
	cout << setprecision(20) << best << endl;
}