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

int n, k;
VPII V[M];
LL dp[M][2];

void DFS(int v, int c, int prv)
{
	vector<LL> adds;
	LL tmp = 0;
	for (auto x : V[v])
	{
		if (x.f != prv)
		{
			DFS(x.f, x.s, v);
		}
		tmp += dp[x.f][0];
		adds.PB(dp[x.f][1] - dp[x.f][0]);
	}
	sort(ALL(adds));
	reverse(ALL(adds));
	
	dp[v][0] = tmp;
	FOR(i, 0, min(k, SIZ(adds)) - 1)
	{
		if (adds[i] > 0)
		{
			dp[v][0] += adds[i];
		}
	}
	dp[v][1] = tmp + c;
	FOR(i, 0, min(k - 1, SIZ(adds)) - 1)
	{
		if (adds[i] > 0)
		{
			dp[v][1] += adds[i];
		}
	}
}

void solve()
{
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
	{
		V[i].clear();
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
	FOR(i, 2, n)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V[a].PB(MP(b, c));
		V[b].PB(MP(a, c));
	}
	DFS(1, 0, 0);
	
	printf("%lld\n", dp[1][0]);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}