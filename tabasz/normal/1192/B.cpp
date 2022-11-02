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
 
#define int LL
#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 1024 * 256;
const LL inf = 2e18 + 1;
 
struct cent
{
	int root, M, tmp, ind;
	unordered_map<int, PII> prze;
	unordered_map<int, int> start;
	VPII D;//add, maxi
	
	cent()
	{
		M = 1;
		tmp = -1;
	}
	
	void pchaj(int v)
	{
		D[2 * v].f += D[v].f;
		D[2 * v + 1].f += D[v].f;
		D[v].f = 0;
	}
	
	void popraw(int v)
	{
		D[v].s = max(D[2 * v].f + D[2 * v].s, D[2 * v + 1].f + D[2 * v + 1].s);
	}
	
	void add(int v, int vp, int vk, int p, int k, int val)
	{
		if (vp > k || vk < p)
		{
			return;
		}
		if (vp >= p && vk <= k)
		{
			D[v].f += val;
			return;
		}
		pchaj(v);
		
		int mid = (vp + vk) / 2;
		add(2 * v, vp, mid, p, k, val);
		add(2 * v + 1, mid + 1, vk, p, k, val);
		popraw(v);
	}
	
	int mxi(int v, int vp, int vk, int p, int k)
	{
		if (vp > k || vk < p || p > k)
		{
			return -inf;
		}
		if (vp >= p && vk <= k)
		{
			return D[v].f + D[v].s;
		}
		pchaj(v);
		
		int mid = (vp + vk) / 2;
		int res = max(mxi(2 * v, vp, mid, p, k), mxi(2 * v + 1, mid + 1, vk, p, k));
		popraw(v);
		return res;
	}
	
	int getbest(int v)
	{
		if (v >= M)
		{
			return v - M;
		}
		if (D[2 * v].f + D[2 * v].s == D[v].s)
		{
			return getbest(2 * v);
		}
		return getbest(2 * v + 1);
	}
	
	int getres()
	{
		int best = D[1].f + D[1].s;
		int v = getbest(1);
		
		PII done = prze[start[v]];
		
		int ml = mxi(1, 0, M - 1, 0, done.f - 1);
		int mr = mxi(1, 0, M - 1, done.s + 1, M - 1);
		int r = best + max(ml, mr);
		debug(v, start[v], done, M);
		debug(best, ml, mr);
		return r;
	}
 
	void query(PII x, int val)
	{
		debug(x, val);
		PII prz = prze[x.f], prz2 = prze[x.s];
		if (prz2.f >= prz.f && prz2.s <= prz.s)
		{
			swap(prz, prz2);
		}
		debug(prz);
		add(1, 0, M - 1, prz.f, prz.s, val);
	}
};
 
int n, q, w, S[M];
VPII V[M];
PII E[M];
LL C[M];
VI cents[M];
vector<cent> X;
int all[2 * M];
 
int sizDFS(int v, int pr)
{
	S[v] = 1;
	for (auto x : V[v])
	{
		if (x.f != pr)
		{
			S[v] += sizDFS(x.f, v);
		}
	}
	return S[v];
}
 
int centrDFS(int v, int s, int pr)
{
	for (auto x : V[v])
	{
		if (x.f != pr && S[x.f] > s / 2)
		{
			return centrDFS(x.f, s, v);
		}
	}
	return v;
}
 
int getCentr(int v)
{
	int s = sizDFS(v, 0);
	return centrDFS(v, s, 0);
}
 
void DFS(int v, cent& x, int st, int pr)
{
	x.tmp++;
	x.start[x.tmp] = st;
	x.prze[v].f = x.tmp;
	for (auto u : V[v])
	{
		if (u.f == pr)
		{
			continue;
		}
		cents[u.s].PB(x.ind);
		
		if (v != x.root)
		{
			DFS(u.f, x, st, v);
		}
		else
		{
			DFS(u.f, x, u.f, v);
		}
	}
	
	x.prze[v].s = x.tmp;
}
 
void DFSdep(int v, cent& x, int pr)
{
	for (auto u : V[v])
	{
		if (u.f == pr)
		{
			continue;
		}
		
		PII prz = x.prze[u.f];
		debug("                           ", x.ind, prz, C[u.s]);
		x.add(1, 0, x.M - 1, prz.f, prz.s, C[u.s]);
		
		DFSdep(u.f, x, v);
	}
}
 
void del(int v, int ind)
{
	FOR(i, 0, SIZ(V[v]) - 1)
	{
		if (V[v][i].s == ind)
		{
			swap(V[v][i], V[v].back());
			V[v].pb();
			break;
		}
	}
}
 
void addall(int v, int val)
{
	v += M;
	all[v] = val;
	while (v > 1)
	{
		v /= 2;
		all[v] = max(all[2 * v], all[2 * v + 1]);
	}
}
 
void jebaj(int v)
{
	cent x;
	x.ind = X.size();
	x.root = getCentr(v);
	
	DFS(x.root, x, 0, 0);
	while (x.M <= x.tmp)
	{
		x.M *= 2;
	}
	x.D.resize(2 * x.M);
	DFSdep(x.root, x, 0);
	
	X.PB(x);
	addall(x.ind, x.getres());
	
	for (auto e : V[x.root])
	{
		del(e.f, e.s);
		jebaj(e.f);
	}
}
 
main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%lld%lld%lld", &n, &q, &w);
	
	FOR(i, 1, n - 1)
	{
		int a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		V[a].PB(MP(b, i));
		V[b].PB(MP(a, i));
		E[i] = MP(a, b);
		C[i] = c;
	}
	
	jebaj(1);
	
	FOR(i, 1, n - 1)
	{
		debug(E[i], cents[i]);
	}
	for (auto x : X)
	{
		debug(x.root, x.M, x.tmp, x.ind);
		debug(x.prze);
		debug(x.start);
		debug("\n");
	}
	int last = 0;
	FOR(i, 1, q)
	{
		int ee, dd;
		scanf("%lld%lld", &dd, &ee);
		
		int e = (ee + last) % w;
		int d = (dd + last) % (n - 1) + 1;
		
		int res = 0;
		debug(last, e, d);
		for (auto ind : cents[d])
		{
			X[ind].query(E[d], e - C[d]);
			addall(X[ind].ind, X[ind].getres());
		}
		C[d] = e;
		res = all[1];
		printf("%lld\n", res);
		last = res;
	}
	return 0;
}