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
const int M = 1024 * 1024;
const LL mod = 998244353;

int n;
vector<LL> V[3];
VPII V2;

LL count(int ind)
{
	LL r = 1, tmp = 1, tmp2 = 1;
	FOR(i, 1, n - 1)
	{
		if (V[ind][i] == V[ind][i - 1])
		{
			tmp++;
			tmp2 = tmp2 * tmp % mod;
		}
		else
		{
			r = r * tmp2 % mod;
			tmp = 1;
			tmp2 = 1;
		}
	}
	return r * tmp2 % mod;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	VPII X;
	FOR(i, 1, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[0].PB(a);
		V[1].PB(b);
		V[2].PB((LL)a * n + b);
		X.PB(MP(a, b));
	}
	sort(ALL(X));
	FOR(i, 0, 2)
	{
		sort(ALL(V[i]));
	}
	LL res = 1;
	FOR(i, 2, n)
	{
		res = res * i % mod;
	}
	debug(count(0), count(1), count(2));
	debug(V[0], V[1], V[2]);
	res -= count(0) + count(1);
	bool boo = 1;
	FOR(i, 1, n - 1)
	{
		if (X[i - 1].s > X[i].s)
		{
			boo = 0;
		}
	}
	if (boo)
	{
		res += count(2);
	}
	while (res < 0)
	{
		res += mod;
	}
	while (res >= mod)
	{
		res -= mod;
	}
	printf("%lld\n", res);
	return 0;
}