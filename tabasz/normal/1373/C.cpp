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

unordered_map<int, int> mapa;

void solve()
{
	mapa.clear();
	string s;
	cin >> s;
	int tmp = 0;
	FOR(i, 0, SIZ(s) - 1)
	{
		if (s[i] == '+')
		{
			tmp++;
		}
		else
		{
			tmp--;
		}
		debug(i, tmp);
		if (mapa.count(tmp) == 0)
		{
			mapa[tmp] = i;
		}
	}
	LL res = 0;
	debug(mapa, s, SIZ(s));
	FOR(i, 1, SIZ(s))
	{
		if (!mapa.count(-i))
		{
			break;
		}
		debug(i, mapa[-i]);
		res += mapa[-i] + 1;
	}
	res += SIZ(s);
	cout << res << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}