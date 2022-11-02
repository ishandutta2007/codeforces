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
const int M = 3003;
const LL mod = 998244353;

int n, m;
string s, t;
unordered_map<int, int> dp[M];
LL cnt;

LL get(int l, int pp)
{
	if (dp[l].count(pp))
	{
		return dp[l][pp];
	}
	cnt++;
	PII p = MP(pp / M, pp % M);
	if (p.s - p.f + 1 > l)
	{
		dp[l][pp] = 0;
		return 0;
	}
	LL r = 0;
	if (p.f > p.s)
	{
		if (l == 0)
		{
			r = 1;
		}
		else
		{
			r = 2 * get(l - 1, pp);
			if (r >= mod)
			{
				r -= mod;
			}
		}
	}
	else if (p.s - p.f + 1 < l)
	{
		if (t[p.f - 1] == s[l - 1])
		{
			r += get(l - 1, (p.f + 1) * M +  p.s);
		}
		r += get(l - 1, p.f * M + p.s);
		if (r >= mod)
		{
			r -= mod;
		}
	}
	else
	{
		if (t[p.f - 1] == s[l - 1])
		{
			r += get(l - 1, (p.f + 1) * M + p.s);
		}
		if (t[p.s - 1] == s[l - 1])
		{
			r += get(l - 1, p.f * M + p.s - 1);
		}
		if (r >= mod)
		{
			r -= mod;
		}
	}
	dp[l][pp] = r;
	return r;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> s >> t;
	n = SIZ(s);
	m = SIZ(t);
	LL r = 0;
	
	FOR(i, 1, n)
	{
		r += get(i, M + m);
		if (r >= mod)
		{
			r -= mod;
		}
	}
	cout << r << "\n";
}