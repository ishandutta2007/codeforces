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
#define int LL
const int M = 1024 * 1024;

LL T[M];

void jebaj(int n, int v, int p, int k)
{
	if (p > k)
	{
		return;
	}
	int ile = (n - v) * 2;
	int tmp = 0;
	if (ile >= p)
	{
		FOR(i, v + 1, n)
		{
			tmp++;
			if (tmp >= p && tmp <= k)
			{
				printf("%lld ", v);
			}
			tmp++;
			if (tmp >= p && tmp <= k)
			{
				printf("%lld ", i);
			}
		}
	}
	if (ile > k)
	{
		return;
	}
	jebaj(n, v + 1, max(p - ile, 1LL), min((LL)k - ile, T[n]));
}

void solve()
{
	int n, p, k;
	scanf("%lld%lld%lld", &n, &p, &k);
	jebaj(n, 1, p, k);
	if (k == T[n] + 1)
	{
		printf("1");
	}
	printf("\n");
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	FOR(i, 1, M - 1)
	{
		T[i] = (LL)i * (i - 1); 
	}
	int t;
	scanf("%lld", &t);
	while (t--)
	{
		solve();
	}
}