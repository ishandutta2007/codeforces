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
const int M = 1024;

int n, S[M], cent;
VPII V[M];
PII E[M];
int co[M], C[M];

void dfs(int v, int p)
{
	S[v] = 1;
	for (auto x : V[v])
	{
		if (x.f != p)
		{
			dfs(x.f, v);
			S[v] += S[x.f];
		}
	}
}

int dfs2(int v, int p)
{
	for (auto x : V[v])
	{
		if (x.f != p && S[x.f] * 2 >= n)
		{
			return dfs2(x.f, v);
		}
	}
	return v;
}

void findcent()
{
	dfs(1, 0);
	cent = dfs2(1, 0);
}

int DFS(int v, int p, int curr, int nxt, int skok)
{
	for (auto x : V[v])
	{
		if (x.f == p)
		{
			continue;
		}
		C[x.s] = nxt - curr;
		nxt = DFS(x.f, v, nxt, nxt + skok, skok);
	}
	return nxt;
}

int Q[M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n - 1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(MP(b, i));
		V[b].PB(MP(a, i));
		E[i] = MP(a, b);
	}
	findcent();
	
	FOR(i, 1, M - 1)
	{
		Q[i] = -1;
	}
	VPII X;
	for (auto x : V[cent])
	{
		for (int i = M - 1; i >= S[x.f]; i--)
		{
			if (Q[i] == -1 && Q[i - S[x.f]] != -1)
			{
				Q[i] = x.f;
			}
		}
	}
	int tmp = 0;
	FORD(i, n / 2, 0)
	{
		if (Q[i] != -1)
		{
			debug(i, Q[i]);
			tmp = i;
			int x = Q[i], s = i;
			while (s != 0)
			{
				debug(x, s);
				co[x] = 1;
				s -= S[x];
				x = Q[s];
			}
			break;
		}
	}
	debug(tmp);
	tmp++;

	int nxt1 = 1, nxt2 = tmp;
	for (auto x : V[cent])
	{
		debug(x, co[x.f]);
		if (co[x.f] == 1)
		{
			C[x.s] = nxt1;
			nxt1 = DFS(x.f, cent, nxt1, nxt1 + 1, 1);
		}
		else
		{
			C[x.s] = nxt2;
			nxt2 = DFS(x.f, cent, nxt2, nxt2 + tmp, tmp);
		}
	}
	FOR(i, 1, n - 1)
	{
		printf("%d %d %d\n", E[i].f, E[i].s, C[i]);
	}
	return 0;
}