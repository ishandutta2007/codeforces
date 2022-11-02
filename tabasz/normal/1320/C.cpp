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
const int M = 1024 * 1024;
const LL inf = 1e16L;

struct lol
{
	int x, y, z;
};

int n, m, pp;
PII D[2 * M];
vector<lol> X;
map<int, int> mapa;

bool cmp(lol a, lol b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

void add(int v, int vp, int vk, int p, int k, int val)
{
	if (vp > k || vk < p)
	{
		return;
	}
	if (vp >= p && vk <= k)
	{
		D[v].f += val;
		return;
	}
	int mid = (vp + vk) / 2;
	add(2 * v, vp, mid, p, k, val);
	add(2 * v + 1, mid + 1, vk, p, k, val);
	D[v].s = max(D[2 * v].f + D[2 * v].s, D[2 * v + 1].f + D[2 * v + 1].s);
}

int32_t main()
{
	scanf("%lld%lld%lld", &n, &m, &pp);
	FOR(i, 1, n)
	{
		int a, c;
		scanf("%lld%lld", &a, &c);
		X.PB({a, -1, c});
	}
	add(1, 0, M - 1, 0, M - 1, -inf);
	FOR(i, 1, m)
	{
		int b, c;
		scanf("%lld%lld", &b, &c);
		if (mapa.count(b) == 0)
		{
			mapa[b] = c;
		}
		else
		{
			mapa[b] = min(c, mapa[b]);
		}
		//add(1, 0, M - 1, b, b, inf - c);
	}
	for (auto x : mapa)
	{
		add(1, 0, M - 1, x.f, x.f, inf - x.s);
	}
	FOR(i, 1, pp)
	{
		int x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		X.PB({x, y, z});
	}
	sort(ALL(X), cmp);
	LL res = -inf;
	for (auto x : X)
	{
		if (x.y == -1)
		{
			maxi(res, D[1].f + D[1].s - x.z);
		}
		else
		{
			add(1, 0, M - 1, x.y + 1, M - 1, x.z);
		}
	}
	printf("%lld\n", res);
}