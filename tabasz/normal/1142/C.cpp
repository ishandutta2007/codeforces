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

#define int LL
#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 1024 * 128;

VPII V;
int n;

bool better(PII x, PII a, PII b)
{
	return (a.s - x.s) * (x.f - b.f) >= (b.s - x.s) * (x.f - a.f);
}

main()
{
	scanf("%lld", &n);
	FOR(i, 1, n)
	{
		int x, y;
		scanf("%lld%lld", &x, &y);
		V.PB(MP(-x, y - x * x));
	}
	sort(ALL(V));
	VPII X;
	
	for (auto x : V)
	{
		while (!X.empty() && X.back().f == x.f)
		{
			X.pop_back();
		}
		while (SIZ(X) > 1 && better(X[SIZ(X) - 2], X.back(), x))
		{
			X.pop_back();
		}
		X.PB(x);
	}
	
	printf("%lld\n", SIZ(X) - 1);
	return 0;
}