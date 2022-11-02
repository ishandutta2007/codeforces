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
const int M = 1024 * 256;
const LL mod = 1e9 + 7;

LL gcd(LL a, LL b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int n;
VI V[M];
LL B[M], res;

void DFS(int v, int pr, vector<PLL> X)
{
	for (auto& x : X)
	{
		x.f = gcd(x.f, B[v]);
	}
	X.PB(MP(B[v], 1));
	vector<PLL> X2;
	for (auto x : X)
	{
		if (X2.empty() || X2.back().f != x.f)
		{
			X2.PB(x);
		}
		else
		{
			X2.back().s += x.s;
		}
	}
	debug(v, pr, X, X2);
	for (auto x : X2)
	{
		res = (res + x.f * x.s) % mod;
	}
	for (auto u : V[v])
	{
		if (u != pr)
		{
			DFS(u, v, X2);
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		scanf("%lld", B + i);
	}
	FOR(i, 2, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	res = B[1];
	vector<PLL> X;
	X.PB(MP(B[1], 1));
	for (auto x : V[1])
	{
		DFS(x, 1, X);
	}
	
	printf("%lld\n", res);
	return 0;
}