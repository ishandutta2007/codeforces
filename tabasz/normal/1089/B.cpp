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

struct general_matching
{
	int n;
	vector<int> *g;
	int *match, *p, *base, *q;
	bool *used, *blossom;
	general_matching(int siz)
	{
		n = siz;
		match = new int[n];
		p = new int[n];
		base = new int[n];
		q = new int[n];
		used = new bool[n];
		blossom = new bool[n];
		g = new vector<int>[n];
	}
	
	void addedge(int a, int b)
	{
		g[a].PB(b);
		g[b].PB(a);
	}

	int lca (int a, int b)
	{
		bool used[n] = {0};
		while (true)
		{
			a = base[a];
			used[a] = true;
			if (match[a] == -1) break;
			a = p[match[a]];
		}
		while (true)
		{
			b = base[b];
			if (used[b]) return b;
			b = p[match[b]];
		}
	}

	void mark_path(int v, int b, int children)
	{
		while (base[v] != b)
		{
			blossom[base[v]] = blossom[base[match[v]]] = true;
			p[v] = children;
			children = match[v];
			v = p[match[v]];
		}
	}

	int find_path(int root)
	{
		memset(used, 0, n);
		memset(p, -1, n * sizeof(int));
		REP(i, n)
			base[i] = i;
		used[root] = true;
		int qh = 0, qt = 0;
		q[qt++] = root;
		while (qh < qt)
		{
			int v = q[qh++];
			for (auto to : g[v])
			{
				if (base[v] == base[to] || match[v] == to)
					continue;
				if (to == root || (match[to] != -1 && p[match[to]] != -1))
				{
					int curbase = lca (v, to);
					memset(blossom, 0, n);
					mark_path(v, curbase, to);
					mark_path(to, curbase, v);
					REP(i, n)
					{
						if (blossom[base[i]])
						{
							base[i] = curbase;
							if (!used[i])
							{
								used[i] = true;
								q[qt++] = i;
							}
						}
					}
				}
				else if (p[to] == -1)
				{
					p[to] = v;
					if (match[to] == -1)
						return to;
					to = match[to];
					used[to] = true;
					q[qt++] = to;
				}
			}
		}
		return -1;
	}

	void solve()
	{
		memset(match, -1, n * sizeof(int));
		//// tutaj odpalamy zachlana, aby reszta zrobila sie (2-3 razy) szybciej
		REP(i, n)
		{
			if (match[i] != -1)
				continue;
			for (auto j : g[i])
			{
				if (match[j] == -1)
				{
					match[j] = i;
					match[i] = j;
					break;
				}
			}
		}
		/// koniec odpalania zachlana
		REP(i, n)
		{
			if (match[i] == -1)
			{
				int v = find_path(i);
				while (v != -1)
				{
					int pv = p[v], ppv = match[pv];
					match[v] = pv;
					match[pv] = v;
					v = ppv;
				}
			}
		}
	}
};

int n, m;
char C[10000];

void solve()
{
	scanf("%d%d", &n, &m);
	general_matching match(2 * n + m);
	FOR(i, 0, n - 1)
	{
		scanf("%s", C);
		match.addedge(i, i + n);
		FOR(j, 0, m - 1)
		{
			if (C[j] == '1')
			{
				match.addedge(i, 2 * n + j);
				match.addedge(i + n, 2 * n + j);
			}
		}
	}
	match.solve();
	int res = 0;
	FOR(i, 0, 2 * n + m - 1)
	{
		if (match.match[i] != -1)
		{
			debug(i, match.match[i]);
			res++;
		}
	}
	printf("%d\n", res / 2 - n);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}