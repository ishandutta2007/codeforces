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

LL res;
int n[3];
VI V[3];

void check(int a, int b, int c)
{
	LL r = (LL)(a - b) * (a - b) + (LL)(c - b) * (c - b) + (LL)(a - c) * (a - c);
	mini(res, r);
}

int getwier(int i, int x)
{
	int st = 0, en = SIZ(V[i]) - 1, mid = (st + en) / 2, r = SIZ(V[i]);
	while (st <= en)
	{
		if (V[i][mid] >= x)
		{
			mini(r, mid);
			en = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
		mid = (st + en) / 2;
	}
	if (r == SIZ(V[i]))
	{
		return inf;
	}
	return V[i][r];
}

int getmier(int i, int x)
{
	int st = 0, en = SIZ(V[i]) - 1, mid = (st + en) / 2, r = -1;
	while (st <= en)
	{
		if (V[i][mid] <= x)
		{
			maxi(r, mid);
			st = mid + 1;
		}
		else
		{
			en = mid - 1;
		}
		mid = (st + en) / 2;
	}
	if (r == -1)
	{
		return inf;
	}
	return V[i][r];
}

void jebaj(int i, int x)
{
	int y = getwier((i + 1) % 3, x);
	int z = getwier((i + 2) % 3, x);
	if (y == inf || z == inf)
	{
		return;
	}
	check(x, y, z);
	int ind = (i + 1) % 3;
	if (z < y)
	{
		swap(z, y);
		ind = (i + 2) % 3;
	}
	int yy = getwier(ind, x + (z - x) / 2);
	if (yy != inf)
	{
		check(x, yy, z);
	}
	yy = getmier(ind, x + (z - x) / 2);
	if (yy != inf)
	{
		check(x, yy, z);
	}
}

void solve()
{
	scanf("%d%d%d", n, n + 1, n + 2);
	res = INF * 6;
	FOR(i, 0, 2)
	{
		V[i].clear();
		FOR(j, 1, n[i])
		{
			int a;
			scanf("%d", &a);
			V[i].PB(a);
		}
		sort(ALL(V[i]));
	}
	FOR(i, 0, 2)
	{
		for (auto x : V[i])
		{
			jebaj(i, x);
		}
	}
	printf("%lld\n", res);
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}