/*input
9
88 22 83 14 95 91 98 53 11
3 24
7 -8
1 67
1 64
9 65
5 12
6 -80
3 8
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

#define MX 100005

int n;
int a[MX];
vector<pii> adj[MX];
int cnt[MX];
int ans = 0;

bitset<MX> vis;

void dfs1(int s,int p){
	cnt[s] = 1;
	for(auto u:adj[s]){
		if(u.F == p) continue;
		dfs1(u.F,s);
		cnt[s] += cnt[u.F];
	}
}

void dfs2(int s,int p,int cur){
	// cout << s << " " << cur << " " << a[s] << " --\n";
	if(cur > a[s]){
		// cout << s << "---\n";
		ans += cnt[s];
		return;
	}
	for(auto u: adj[s]){
		if(u.F == p) continue;
		dfs2(u.F,s,max(cur+u.S,u.S));
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n) cin >> a[i];
	REP(i,n-1){
		int v,w; cin >> v >> w;
		adj[i+1].pb({v-1,w});
		adj[v-1].pb({i+1,w});
	}
	// REP(i,n){
	// 	cout << i << " -------\n";
	// 	cout << adj[i].size() << "--\n";
	// 	for(auto x: adj[i]){
	// 		cout << x.F << " " << x.S << endl;
	// 	}
	// }
	dfs1(0,-1);
	dfs2(0,-1,0);
	cout << ans;
}