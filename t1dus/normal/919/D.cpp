/*input
10 14
xzyzyzyzqx
1 2
2 4
3 5
4 5
2 6
6 8
6 5
2 10
3 9
10 9
4 6
1 10
2 8
3 7
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,m;
string s;
vi adj[300005];
int vis[300005];
int deg[300005];
int dp[300005][30];
vi v;

bool check(){
	queue<int> q;
	REP(i,n) if(!deg[i]) q.push(i);
	int cnt = q.size();
	while(!q.empty()){
		int u = q.front();
		q.pop();
		v.pb(u);
		for(auto v:adj[u]){
			deg[v] --;
			if(!deg[v]){
				cnt ++;
				q.push(v);
			}
		}
	}
	// cout << cnt << endl;
	return cnt != n;
}

void solve(int u){
	vis[u] = 1;
	REP(i,26) dp[u][i] = 0;
	for(auto v:adj[u]){
		if(!vis[v]) solve(v);
		REP(i,26) remax(dp[u][i],dp[v][i]);
	}
	dp[u][s[u]-'a']++;
}

signed main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);


	cin >> n >> m >> s;
	REP(i,m){
		int u,v; //cin >> u >> v;
		scanf("%d%d",&u,&v);
		u --; v --;
		deg[v] ++;
		adj[u].pb(v);
	}
	if(check()){
		cout << -1;
		return 0;
	}
	REP(i,n+5) vis[i] = 0;
	int ans = 0;
	for(auto i:v){
		if(!vis[i]) solve(i);
		REP(j,26) remax(ans,dp[i][j]); 
	}
	cout << ans << endl;
}