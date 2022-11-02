#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define pb pop_back
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
Sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
Sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
Sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
#define int LL
#define ll LL
#define PLL pair<LL, LL>
const LL M = 1024 * 1024;
const ll inf = 1e9 + 7;

struct point
{
	int x, y, a, i;
};
int n;
LL dp[M], res;
vector<point> V;

bool cmp(point x, point y)
{
	if (x.x == y.x)
	{
		return x.i < y.i;
	}
	return x.x > y.x;
}

// source: https://github.com/niklasb/contest-algos/blob/master/convex_hull/dynamic.cpp
const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return (LD)(b - s->b) / x < (LD)(s->m - m);
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (LD)(x->b - y->b)*(z->m - y->m) >= (LD)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    Line eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l;
    }
};

main()
{
	scanf("%lld", &n);
	FOR(i, 1, n)
	{
		point x;
		x.i = i;
		scanf("%lld%lld%lld", &x.x, &x.y, &x.a);
		V.PB(x);
	}
	point xx;
	xx.i = 0;
	xx.x = 0;
	xx.y = inf;
	xx.a = 0;
	V.PB(xx);
	sort(ALL(V), cmp);
	
	HullDynamic hull;
	hull.insert_line(0, 0);
	for (auto x : V)
	{
		Line xx = hull.eval(inf - x.x);
		while (hull.begin() != hull.lower_bound(xx))
		{
			hull.erase(hull.begin());
		}
		LL r = xx.m * (inf - x.x) + xx.b - x.a;
		maxi(res, r + x.x * x.y);
		
		LL m = x.y;
		LL b = r - x.y * (inf - x.x);
		hull.insert_line(m, b);
	}
	
	printf("%lld\n", res);
	return 0;
}