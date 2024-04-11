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
const int M = 1024 * 512;
const LL p1 = 10009;
const LL p2 = 10037;
const LL mod1 = 1000000009;
const LL mod2 = 1000000033;

int n, m;
LL T[M];
VI V[M];
map<LL, LL> mapa;

LL gcd(LL a, LL b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

LL has(VI VV)
{
	pair<LL, LL> hh = MP(0, 0);
	for (auto x : VV)
	{
		hh.f = (hh.f * p1 + x) % mod1;
		hh.s = (hh.f * p2 + x) % mod2;
	}
	return hh.f * mod2 + hh.s; 
}

void solve()
{
	mapa.clear();
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		V[i].clear();
		scanf("%lld", T + i);
	}
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[b].PB(a);
	}
	FOR(i, 1, n)
	{
		sort(ALL(V[i]));
		if (V[i].empty())
		{
			continue;
		}
		debug(i, V[i], T[i]);
		mapa[has(V[i])] += T[i];
	}
	LL res = 0;
	for (auto x : mapa)
	{
		res = gcd(res, x.s);
	}
	printf("%lld\n", res);
}

int32_t main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}