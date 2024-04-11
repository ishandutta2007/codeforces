//tabasz
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
const int inf = 1e9+7;
const LL INF = 1e18L+7;

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
const int M = 1024 * 512;

int n, m, k;
set<PII> pola;
multiset<int> mxi;
PII D[2 * M];//add, mxi

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
	if (vk < p || vp > k)
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

int mx(int v, int vp, int vk, int p, int k)
{
	if (vk < p || vp > k)
	{
		return -inf;
	}
	if (vp >= p && vk <= k)
	{
		return D[v].f + D[v].s;
	}
	pchaj(v);
	int mid = (vp + vk) / 2;
	int r = max(mx(2 * v, vp, mid, p, k), mx(2 * v + 1, mid + 1, vk, p, k));
	popraw(v);
	return r;
}

void ad(int x)
{
	debug(x);
	mxi.insert(x);
	add(1, 0, M - 1, 0, x - 1, 1);
}

void rem(int x)
{
	debug(x);
	mxi.erase(mxi.find(x));
	add(1, 0, M - 1, 0, x - 1, -1);
}

int get()
{
	if (mxi.empty())
	{
		return 0;
	}
	auto it = mxi.end();
	it--;
	int high = *it;
	return mx(1, 0, M - 1, 0, max(n, high)) - n;
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%d", &n, &k, &m);
	FOR(i, 0, 2 * n)
	{
		add(1, 0, M - 1, i, i, i);
	}
	FOR(i, 1, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int h = b + abs(k - a);
		debug(a, b, h);
		if (!pola.count(MP(a, b)))
		{
			pola.insert(MP(a, b));
			ad(h);
		}
		else
		{
			pola.erase(MP(a, b));
			rem(h);
		}
		printf("%d\n", get());
	}
}