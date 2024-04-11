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
const int inf = 1e9 + 7;

int n, m, k;
VI V[M], X, VT[M];
PII dist[M];

int32_t main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	{
		dist[i] = MP(inf, 0);
	}
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[b].PB(a);
		VT[a].PB(b);
	}
	scanf("%d", &k);
	FOR(i, 1, k)
	{
		int a;
		scanf("%d", &a);
		X.PB(a);
	}
	dist[X.back()] = MP(0, 1);
	queue<int> Q;
	Q.push(X.back());
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (auto x : V[v])
		{
			if (dist[x].f == inf)
			{
				dist[x] = MP(dist[v].f + 1, dist[v].s);
				Q.push(x);
			}
			else if (dist[x].f == dist[v].f + 1)
			{
				dist[x].s = 2;
			}
		}
	}
	int mi = 0, ma = 0;
	
	debug(X);
	FOR(i, 1, n)
	{
		debug(i, dist[i]);
	}
	FOR(i, 0, SIZ(X) - 2)
	{
		int l = SIZ(X) - i - 1;
		int my = dist[X[i]].f;
		debug(l, my, X[i], X[i + 1]);
		int ile = 0, in = 0;
		for (auto x : VT[X[i]])
		{
			if (dist[x].f + 1 == dist[X[i]].f)
			{
				ile++;
				if (x == X[i + 1])
				{
					in = 1;
				}
			}
		}
		if (!in)
		{
			mi++;
		}
		if (ile > 1 || !in)
		{
			ma++;
		}
	}
	
	printf("%d %d\n", mi, ma);
}