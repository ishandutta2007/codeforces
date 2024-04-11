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
const int M = 40;

int d, mod, ile[M];

void solve()
{
	scanf("%lld%lld", &d, &mod);
	FOR(i, 0, M - 1)
	{
		ile[i] = 0;
	}
	ile[1] = 1;
	int mx = 1, tmp = 1;
	while (2 * mx + 1 <= d)
	{
		int mx2 = 2 * mx + 1;
		tmp++;
		ile[tmp] = mx2 - mx;
		mx = mx2;
	}
	tmp++;
	ile[tmp] = d - mx;
	LL res = 1;
	FOR(i, 1, M - 1)
	{
		res = (res * (ile[i] + 1)) % mod;
	}
	printf("%lld\n", (res + mod - 1) % mod);
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int t;
	scanf("%lld", &t);
	while (t--)
	{
		solve();
	}
}