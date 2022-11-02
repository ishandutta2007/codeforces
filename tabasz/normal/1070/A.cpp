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
#define mp make_pair
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

const int N = 5007;

int dist[N][507];
PII skad[N][507];
int jak[N][507];

int d, s;

queue<PII> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> d >> s;
	
	for(int i = 0; i <= s; ++i)
	{
		for(int j = 0; j < d; ++j)
		{
			dist[i][j] = inf;
		}
	}
	
	dist[0][0] = 0;
	Q.emplace(0, 0);
	
	while(!Q.empty())
	{
		int sum = Q.front().st;
		int mod = Q.front().nd;
		Q.pop();
		
		for(int i = 0; i < 10; ++i)
		{
			int nsum = sum+i;
			int nmod = (10*mod+i)%d;
		
			if(nsum<=s && dist[nsum][nmod]==inf)
			{
				dist[nsum][nmod] = dist[sum][mod] + 1;
				skad[nsum][nmod] = mp(sum, mod);
				jak[nsum][nmod] = i;
				Q.emplace(nsum, nmod);
			}
		}
	}
	
	if(dist[s][0]==inf)
	{
		cout << -1 << endl;
		return 0;
	}
	
	VI ans;
	
	int sum = s, mod = 0;
	
	while(dist[sum][mod])
	{
		ans.pb(jak[sum][mod]);
		int nsum = skad[sum][mod].st;
		int nmod = skad[sum][mod].nd;
		sum = nsum;
		mod = nmod;
	}		
	
	reverse(ALL(ans));
	
	for(auto it:ans)
		cout << it;
		
	cout << endl;
}