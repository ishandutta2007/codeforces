/*input
4
1 4
2 4
3 4
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

#define MX 200005

int n;
vector<pii> adj[MX];
int dist1[MX],dist2[MX];
int cnt = 0;

void dfs(int s,int p,int d1 = 0,int d2 = 0){
	dist1[s] = d1;
	dist2[s] = d2;
	for(auto u:adj[s]){
		if(u.F == p) continue;
		dfs(u.F,s,d1+1,d2+u.S);
		cnt += u.S;
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb({v,0});
		adj[v].pb({u,1});
	}
	dfs(1,-1);
	int ans = MX;
	int tot[MX];
	FOR(i,1,n+1){
		tot[i] = cnt+dist1[i]-2*dist2[i];
		remin(ans,tot[i]);
	}
	cout << ans << endl;
	FOR(i,1,n+1){
		if(tot[i] == ans) cout << i << " ";
	}
}