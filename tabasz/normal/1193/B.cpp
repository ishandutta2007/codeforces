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
const int M = 1024 * 128;
const LL inf = 2e18 + 1;

VI V[M];
set<PLL> secik[M];//time, val
int W[M], D[M];
int n, m, k;

void add_one(int a, LL pos, LL val)
{
	auto it = secik[a].lower_bound(MP(pos, 0));
	if (it == secik[a].end() || (*it).f > pos)
	{
		secik[a].insert(MP(pos, val));
	}
	else
	{
		LL old = (*it).s;
		secik[a].erase(it);
		secik[a].insert(MP(pos, old + val));
	}
}

void merge(int a, int b)
{
	if (SIZ(secik[a]) < SIZ(secik[b]))
	{
		swap(secik[a], secik[b]);
	}
	for (auto x : secik[b])
	{
		add_one(a, x.f, x.s);
	}
	
	secik[b].clear();
}

void add(int a)
{
	LL tmp = W[a];
	
	while (tmp > 0)
	{
		auto it = secik[a].upper_bound(MP(D[a], inf));
		if (it == secik[a].end())
		{
			break;
		}
		PLL pre = *it;
		secik[a].erase(it);
		LL mi = min(tmp, pre.s);
		tmp -= mi;
		pre.s -= mi;
		if (pre.s > 0)
		{
			secik[a].insert(pre);
		}
	}
	
	add_one(a, D[a], W[a]);
}

void DFS(int v)
{
	for (auto x : V[v])
	{
		DFS(x);
	}
	if (SIZ(V[v]) > 0)
	{
		swap(secik[v], secik[V[v][0]]);
	}
	FOR(i, 1, SIZ(V[v]) - 1)
	{
		merge(v, V[v][i]);
	}
	debug("pree         ", v, secik[v], D[v], W[v]);
	
	add(v);
	
	debug(v, secik[v]);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 2, n)
	{
		int a;
		scanf("%d", &a);
		V[a].PB(i);
	}
	FOR(i, 1, m)
	{
		int v, d, w;
		scanf("%d%d%d", &v, &d, &w);
		W[v] = w;
		D[v] = d;
	}
	D[1] = k + 1;
	
	DFS(1);
	
	LL res = 0;
	for (auto x : secik[1])
	{
		res += x.s;
	}
	printf("%lld\n", res);
	return 0;
}