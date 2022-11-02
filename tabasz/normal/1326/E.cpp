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
const int M = 1024 * 512;

int n;
PII D[2 * M], T[2 * M];
set<int> secik;

void add(int v, int x)
{
	v += M;
	T[v] = MP(x, v - M);
	while (v > 1)
	{
		v /= 2;
		T[v] = max(T[2 * v], T[2 * v + 1]);
	}
}

int mxx(int p, int k)
{
	p += M;
	k += M;
	PII r = max(T[p], T[k]);
	while (p / 2 != k / 2)
	{
		if (p % 2 == 0)
		{
			maxi(r, T[p + 1]);
		}
		p /= 2;
		if (k % 2 == 1)
		{
			maxi(r, T[k - 1]);
		}
		k /= 2;
	}
	return r.s;
}

void add2(int v, int vp, int vk, int p, int k, int x)
{
	if (vp > k || vk < p)
	{
		return;
	}
	if (vp >= p && vk <= k)
	{
		D[v].f += x;
		return;
	}
	int mid = (vp + vk) / 2;
	add2(2 * v, vp, mid, p, k, x);
	add2(2 * v + 1, mid + 1, vk, p, k, x);
	D[v].s = min(D[2 * v].f + D[2 * v].s, D[2 * v + 1].f + D[2 * v + 1].s);
}

int mn(int v, int val)
{
	if (D[v].s + D[v].f > val)
	{
		return M;
	}
	if (v >= M)
	{
		return v - M;
	}
	val -= D[v].f;
	if (D[2 * v].f + D[2 * v].s <= val)
	{
		return mn(2 * v, val);
	}
	return mn(2 * v + 1, val);
}

int piermr(int v, int vp, int vk, int p, int val)
{
	if (vk < p)
	{
		return M;
	}
	if (vp >= p)
	{
		return mn(v, val);
	}
	int mid = (vp + vk) / 2;
	int r = piermr(2 * v, vp, mid, p, val - D[v].f);
	if (r == M)
	{
		return piermr(2 * v + 1, mid + 1, vk, p, val - D[v].f);
	}
	return r;
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		add(i, a);
		secik.insert(-i);
	}
	
	FOR(i, 1, n)
	{
		printf("%d ", -(*secik.begin()));
		//debug(i, secik);
		int a;
		scanf("%d", &a);
		int ind = piermr(1, 0, M - 1, a, 0);
		int x = mxx(1, ind);
		//debug(a, ind, x);
		add2(1, 0, M - 1, x, n, 1);
		add2(1, 0, M - 1, a, n, -1);
		secik.erase(-T[M + x].f);
		add(x, 0);
	}
	printf("\n");
}