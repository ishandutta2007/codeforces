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
const int M = 1024 * 256;

LL res;
VI V[M];
int S[M], R[M], dep[M];
int n, k;

void DFS(int v, int pr, int d)
{
	S[v] = 1;
	dep[v] = d;
	for (auto x : V[v])
	{
		if (x != pr)
		{
			DFS(x, v, d + 1);
			S[v] += S[x];
		}
	}
}

void DFS2(int v, int pr, int lol)
{
	if (R[v] == 0)
	{
		lol++;
	}
	else
	{
		res += lol;
	}
	for (auto x : V[v])
	{
		if (x != pr)
		{
			DFS2(x, v, lol);
		}
	}
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &k);
	FOR(i, 2, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	DFS(1, 0, 0);
	VPII X;
	FOR(i, 1, n)
	{
		X.PB(MP(S[i] - 1 - dep[i], i));
	}
	sort(ALL(X));
	debug(X);
	FOR(i, 0, k - 1)
	{
		R[X[i].s] = 1;
	}
	DFS2(1, 0, 0);
	printf("%lld\n", res);
}