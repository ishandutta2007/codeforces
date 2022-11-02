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

int n, q, k, m;
VI V[M];
VPII V2[M];
int T[20][M], pr[M], po[M], dep[M], prr, R[M], speed[M], start[M], ask[M];

void DFS(int v, int pre, int de)
{
	prr++;
	pr[v] = prr;
	dep[v] = de;
	T[0][v] = pre;
	for (auto x : V[v])
	{
		if (x != pre)
		{
			DFS(x, v, de + 1);
		}
	}
	po[v] = prr;
}

bool ancestor(int a, int b)
{
	return pr[a] <= pr[b] && po[a] >= po[b];
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
	FORD(i, 19, 0)
	{
		if (!ancestor(T[i][a], b))
		{
			a = T[i][a];
		}
	}
	return T[0][a];
}

bool cmp(int a, int b)
{
	return pr[a] < pr[b];
}

void solve()
{
	scanf("%d%d", &k, &m);
	VI VV;
	FOR(i, 1, k)
	{
		int v, s;
		scanf("%d%d", &v, &s);
		speed[i] = s;
		start[i] = v;
		VV.PB(v);
	}
	FOR(i, 1, m)
	{
		int a;
		scanf("%d", &a);
		ask[i] = a;
		VV.PB(a);
	}
	sort(ALL(VV), cmp);
	VV.resize(unique(ALL(VV)) - VV.begin());
	VI tmp;
	FOR(i, 0, SIZ(VV) - 2)
	{
		tmp.PB(lca(VV[i], VV[i + 1]));
	}
	for (auto x : tmp)
	{
		VV.PB(x);
	}
	sort(ALL(VV), cmp);
	VV.resize(unique(ALL(VV)) - VV.begin());
	
	for (auto x : VV)
	{
		V2[x].clear();
		R[x] = -1;
	}
	tmp.clear();
	tmp.PB(VV[0]);
	FOR(i, 1, SIZ(VV) - 1)
	{
		int x = VV[i];
		while (!ancestor(tmp.back(), x))
		{
			tmp.pb();
		}
		V2[tmp.back()].PB(MP(x, dep[x] - dep[tmp.back()]));
		V2[x].PB(MP(tmp.back(), dep[x] - dep[tmp.back()]));
		tmp.PB(x);
	}
	set<tuple<int, int, int, int>> secik;
	FOR(i, 1, k)
	{
		secik.emplace(0, i, 0, start[i]);
	}
	while (!secik.empty())
	{
		const auto [turn, col, dist, v] = *secik.begin();
		secik.erase(secik.begin());
		if (R[v] != -1)
		{
			continue;
		}
		R[v] = col;
		for (auto x : V2[v])
		{
			if (R[x.f] != -1)
			{
				continue;
			}
			int dd = dist + x.s;
			int tt = (dd + speed[col] - 1) / speed[col];
			secik.emplace(tt, col, dd, x.f);
		}
	}
	FOR(i, 1, m)
	{
		printf("%d ", R[ask[i]]);
	}
	printf("\n");
}

int32_t main()
{
	scanf("%d", &n);
	FOR(i, 2, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	DFS(1, 0, 0);
	po[0] = prr;
	FOR(i, 1, 19)
	{
		FOR(j, 1, n)
		{
			T[i][j] = T[i - 1][T[i - 1][j]];
		}
	}
	scanf("%d", &q);
	FOR(i, 1, q)
	{
		solve();
	}
}