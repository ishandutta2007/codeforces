#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "
#define int LL
const int M = 1024;
const LL mod = 998244353;

int d;
LL sil[M], odw[M];
VI dzie;

int ile(int x, int p)
{
	int r = 0;
	while (x % p == 0)
	{
		r++;
		x /= p;
	}
	return r;
}

int solv(int a, int b)
{
	VI V;
	int s = 0;
	for (auto x : dzie)
	{
		int y = abs(ile(a, x) - ile(b, x));
		if (y != 0)
		{
			V.PB(y);
		}
		s += y;
	}
	LL r = sil[s];
	for (auto x : V)
	{
		r = r * odw[x] % mod;
	}
	return r;
}

void solve()
{
	int a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", solv(a, __gcd(a, b)) * solv(__gcd(a, b), b) % mod);
}

void dziel()
{
	for (int i = 2; i * i <= d; i++)
	{
		if (i * i > d)
		{
			break;
		}
		if (d % i == 0)
		{
			dzie.PB(i);
			while (d % i == 0)
			{
				d /= i;
			}
		}
	}
	if (d != 1)
	{
		dzie.PB(d);
	}
	debug(dzie);
}

LL poww(LL x, LL e)
{
	if (e == 0)
	{
		return 1;
	}
	if (e % 2 == 0)
	{
		return poww(x * x % mod, e / 2);
	}
	return poww(x, e - 1) * x % mod;
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	sil[0] = 1;
	odw[0] = 1;
	FOR(i, 1, M - 1)
	{
		sil[i] = sil[i - 1] * i % mod;
		odw[i] = poww(sil[i], mod - 2);
	}
	int t;
	scanf("%lld%lld", &d, &t);
	dziel();
	FOR(i, 1, t)
	{
		solve();
	}
}