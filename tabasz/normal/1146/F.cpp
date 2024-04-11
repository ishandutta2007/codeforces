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
const LL mod = 998244353;
const int M = 1024 * 256;

int n;
VI V[M];
LL dp[M][2];//konfy, konfy+kolory

void DFS(int v)
{
	for (auto x : V[v])
	{
		DFS(x);
	}
	if (SIZ(V[v]) == 0)
	{
		dp[v][0] = 1;
		dp[v][1] = 1;
		return;
	}
	dp[v][0] = 1;
	dp[v][1] = 1;
	LL tmp = 1;
	vector<LL> X;
	for (auto x : V[v])
	{
		dp[v][1] *= (dp[x][0] + dp[x][1]);
		dp[v][1] %= mod;
		tmp = (tmp * dp[x][0]) % mod;
		X.PB(tmp);
	}
	dp[v][0] = dp[v][1];
	debug(dp[v][1]);
	dp[v][1] = (dp[v][1] - tmp + mod) % mod;
	debug(dp[v][1]);
	tmp = 1;
	FORD(i, SIZ(V[v]) - 1, 0)
	{
		LL r = tmp;
		if (i > 0)
		{
			r = (r * X[i - 1]) % mod;
		}
		r = (r * dp[V[v][i]][1]) % mod;
		debug("lol", V[v][i], r, tmp);
		tmp = (tmp * dp[V[v][i]][0]) % mod;
		dp[v][0] = (dp[v][0] - r + mod) % mod;
	}
	debug(v, dp[v][0], dp[v][1]);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 2, n)
	{
		int a;
		scanf("%d", &a);
		V[a].PB(i);
	}
	DFS(1);
	printf("%lld\n", dp[1][0] % mod);
	return 0;
}