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
const int M = 1024 * 512;

int n, T[M], vis[M], res;
vector<PII> V[M];
PII dp[2][M];
int dp2[M];

void DFS(int v)
{
	vis[v] = 1;
	
	vector<PII> X;
	for (auto x : V[v])
	{
		if (!vis[x.f])
		{
			DFS(x.f);
			X.PB(MP(max(0LL, dp2[x.f] + T[x.f] - x.s), x.f));
		}
	}
	dp[0][v] = MP(0, 0);
	sort(ALL(X));
	for (auto x : X)
	{
		if (x.f > dp[0][v].f)
		{
			dp[1][v] = dp[0][v];
			dp[0][v] = MP(x.f, x.s);
		}
		else if (x.f > dp[1][v].f)
		{
			dp[1][v] = MP(x.f, x.s);
		}
	}
	maxi(res, dp[0][v].f + T[v]);
	dp2[v] = dp[0][v].f;
}

void DFS2(int v, PII x)
{
	vis[v] = 1;
	maxi(res, x.f + T[v]);
	for (auto p : V[v])
	{
		if (!vis[p.f])
		{
			PII xx = max(x, dp[1][v]);
			if (dp[0][v].s != p.f)
			{
				maxi(xx, dp[0][v]);
			}
			xx.f += T[v] - p.s;
			if (xx.f < 0)
			{
				xx = MP(0, 0);
			}
			DFS2(p.f, xx);
		}
	}
}

main()
{
	scanf("%lld", &n);
	FOR(i, 1, n)
	{
		scanf("%lld", T + i);
	}
	FOR(i, 2, n)
	{
		int a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		V[a].PB(MP(b, c));
		V[b].PB(MP(a, c));
	}
	
	DFS(1);
	FOR(i, 1, n)
	{
		vis[i] = 0;
	}
	DFS2(1, MP(0, 0));
	
	printf("%lld\n", res);
	return 0;
}