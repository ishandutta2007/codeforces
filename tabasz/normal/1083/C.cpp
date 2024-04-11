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

struct node
{
	int good, u, v;
};

int n, q, pr[M], po[M], T[20][M], dep[M], tmpp = 0, TT[M];
vector<int> V[M];
node D[2 * M];

void DFS(int v, int par, int de)
{
	de++;
	dep[v] = de;
	T[0][v] = par;
	tmpp++;
	pr[v] = tmpp;
	for (auto x : V[v])
	{
		DFS(x, v, de);
	}
	po[v] = tmpp;
}

bool ancestor(int v, int u)
{
  return pr[v] <= pr[u] && po[v] >= po[u];
}

int lca(int a, int b)
{
  if (ancestor(a, b))
  {
    return a;
  }
  if (ancestor(b, a))
  {
    return b;
  }
  int i = 19;
  while (i >= 0)
  {
    if (!ancestor(T[i][a], b))
    {
      a = T[i][a];
    }
    i--;
  }
  return T[0][a];
}

node join(node a, node b)
{
	if (!a.good || !b.good)
	{
		return node{0, 0, 0};
	}
	vector<int> V{a.v, b.u, b.v};
	vector<int> X{a.u};
	
	int mind = dep[X[0]];
	for (auto x : V)
	{
		mini(mind, dep[x]);
		bool boo = false;
		FOR(i, 0, SIZ(X) - 1)
		{
			if (ancestor(X[i], x))
			{
				X[i] = x;
				boo = true;
				break;
			}
			if (ancestor(x, X[i]))
			{
				boo = true;
				break;
			}
		}
		if (!boo)
		{
			X.PB(x);
		}
		if (SIZ(X) > 2)
		{
			return node{0, 0, 0};
		}
	}
	if (SIZ(X) == 2)
	{
		if (dep[lca(X[0], X[1])] > mind)
		{
			return node{0, 0, 0};
		}
		return node{1, X[0], X[1]};
	}
	int up = a.u;
	for (auto x : V)
	{
		if (ancestor(x, up))
		{
			up = x;
		}
	}
	return node{1, X[0], up};
}

void add(int v, int val)
{
	v += M;
	D[v].good = 1;
	D[v].u = val;
	D[v].v = val;
	debug(v, v - M, val);
	while (v > 1)
	{
		v /= 2;
		D[v] = join(D[2 * v], D[2 * v + 1]);
		if (D[v].good)
		{
			debug(v, D[v].good, D[v].u, D[v].v);
		}
	}
}

int query()
{
	int v = 1;
	while (!D[v].good)
	{
		v *= 2;
	}
	node x = D[v];
	debug(x.good, x.u, x.v, v);
	while (v < M)
	{
		node xx = join(x, D[v + 1]);
		if (xx.good)
		{
			x = xx;
			v++;
			continue;
		}
		else
		{
			v = 2 * v + 1;
		}
	}
	if (v < 2 * M - 1 && join(x, D[v + 1]).good)
	{
		v++;
	}
	
	return v - M + 1;
}

int main()
{
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		scanf("%d", TT + i);
	}
	FOR(i, 2, n)
	{
		int a;
		scanf("%d", &a);
		V[a].PB(i);
	}
	DFS(1, 0, 0);
	
	po[0] = tmpp;
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			T[i][j] = T[i - 1][T[i - 1][j]];
		}
	}
	
	
	FOR(i, 1, n)
	{
		add(TT[i], i);
	}
	
	scanf("%d", &q);
	FOR(i, 1, q)
	{
		int x, a, b;
		scanf("%d", &x);
		if (x == 2)
		{
			printf("%d\n", query());
		}
		else
		{
			scanf("%d%d", &a, &b);
			add(TT[b], a);
			add(TT[a], b);
			swap(TT[a], TT[b]);
		}
	}
	return 0;
}