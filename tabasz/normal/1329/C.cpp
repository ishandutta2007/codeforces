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
const int M = 1024 * 1024 * 2;

int n, m, T[M], dep[M];
LL sum;
VI V;

int getdep(int v)
{
	if (T[2 * v] == 0 && T[2 * v + 1] == 0)
	{
		return dep[v];
	}
	if (T[2 * v] > T[2 * v + 1])
	{
		return getdep(2 * v);
	}
	return getdep(2 * v + 1);
}

void wyjeb(int v)
{
	if (T[2 * v] == 0 && T[2 * v + 1] == 0)
	{
		T[v] = 0;
		return;
	}
	if (T[2 * v] > T[2 * v + 1])
	{
		T[v] = T[2 * v];
		wyjeb(2 * v);
	}
	else
	{
		T[v] = T[2 * v + 1];
		wyjeb(2 * v + 1);
	}
}

void jebaj(int v)
{
	if (dep[v] > m)
	{
		return;
	}
	int x = getdep(v);
	while (x > m)
	{
		sum -= T[v];
		debug(v, T[v]);
		wyjeb(v);
		V.PB(v);
		x = getdep(v);
	}
	jebaj(2 * v);
	jebaj(2 * v + 1);
}

void solve()
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, (1<<(n + 1)) - 1)
	{
		T[i] = 0;
	}
	sum = 0;
	FOR(i, 1, (1<<n) - 1)
	{
		scanf("%d", T + i);
		sum += T[i];
	}
	V.clear();
	jebaj(1);
	printf("%lld\n", sum);
	for (auto x : V)
	{
		printf("%d ", x);
	}
	printf("\n");
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	dep[1] = 1;
	FOR(i, 1, M / 2 - 1)
	{
		dep[2 * i] = dep[i] + 1;
		dep[2 * i + 1] = dep[i] + 1;
	}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}