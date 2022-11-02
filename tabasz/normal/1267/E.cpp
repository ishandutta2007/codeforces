#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define LL long long
#define LD long double
#define VPII vector<PII>
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " =", (x), " "

#define int ll
const int N = 107;

int n, m, ans;

int t[N][N];
int curr[N];

VI best;

int usun[N];

bool comp(int a, int b) {
    return curr[a] > curr[b];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> t[i][j];
        }
    }   
    
    VI stacje;
    
    for(int i = 1; i <= m; ++i)
        stacje.pb(i);
    
    for(int win = 1; win < n; ++win) {
        for(int s = 1; s <= m; ++s) {
            curr[s] = t[s][win] - t[s][n];
        }
        sort(ALL(stacje), comp);
        VI pref;
        int sum = 0;
        for(int i = 0; i < m; ++i) {
        	sum += curr[stacje[i]];
        	pref.pb(stacje[i]);
        	if(sum >= 0 && i+1>ans) {
        		ans = i+1;
        		best = pref;
        	}
        }
    }
    
    cout << m-ans << endl;
    
    for(auto it:best)
    	usun[it] = 1;
    	
    for(int i = 1; i <= m; ++i) {
    	if(!usun[i])
    		cout << i << " ";
    }
    
    cout << endl;
}