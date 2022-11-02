#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
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
#define ll long long
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.st << ", " << x.nd << ">";}
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

const int N = 30007;

int t, n, m, k;

string s;

int cnt[26];

int dp[N];

void solve()
{
	memset(cnt, 0, sizeof cnt);

	cin >> n >> m >> k >> s;
	
	for(int i = 0; i < k; ++i)
	{
		++cnt[s[i]-'A'];
	}
	
	ll ans = INF;
	
	for(int c = 0; c < 26; ++c)
	{
		for(int i = 0; i <= n; ++i)
		{
			dp[i] = -inf;
		}
		
		dp[0] = 0;
		
		for(int i = 0; i < 26; ++i)
		{
			if(i==c)
				continue;
				
			int x = cnt[i];
				
			for(int j = n; j >= 0; --j)
			{
				dp[j] = max(dp[j], dp[j]+x);
				
				if(j-x>=0)
					dp[j] = max(dp[j], dp[j-x]);
			}	
		}
		
		for(int i = 0; i <= n; ++i)
		{
			int chce = max(0, m-dp[i]);
			
			if(n-i+chce<=cnt[c])
				ans = min(ans, (ll)(n-i)*chce);
		}
	}
	
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> t;
	
	while(t--)
		solve();
}