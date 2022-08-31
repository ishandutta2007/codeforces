/*input
6 0 6
2 1 2
2 3 4
2 5 6
2 3 2
2 5 3
1 1
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

#define SZ 300005

int n,m,q;
vi adj[SZ];
int p[SZ],diam[SZ];
bitset<SZ> vis;
vi cc;
int dist[SZ];

void dfs(int s,int d){
	cc.pb(s);
	vis[s] = 1;
	dist[s] = d;
	for(auto x:adj[s]){
		if(!vis[x]) dfs(x,d+1);
	}
}

int calc(int s){
	cc.clear();
	dfs(s,0);
	int ind = -1,mx = -1;
	for(auto x:cc){
		if(dist[x] > mx) mx = dist[x],ind = x;
		vis[x] = 0;
	}
	cc.clear();
	dfs(ind,0);
	mx = -1;
	for(auto x:cc){
		if(dist[x] > mx) mx = dist[x];
	}
	return mx;
}

int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	p[x] = y;
	// cout << x << " - " << y << " - " << diam[x] << " - " << diam[y] << endl;
	diam[y] = max(max(diam[x],diam[y]),1+((diam[x]+1)/2)+((diam[y]+1)/2));
	// cout << y << " " << diam[y] << endl;
}

void solve(){
	cin >> n >> m >> q;
	FOR(i,1,n+1){
		p[i] = i;
		diam[i] = 0;
	}
	REP(i,m){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		merge(u,v);
	}
	FOR(i,1,n+1){
		if(!vis[i]){
			diam[find(i)] = calc(i);
		}
	}
	REP(i,q){
		int type,x,y;
		cin >> type >> x;
		if(type == 1) cout << diam[find(x)] << endl;
		else{
			cin >> y;
			merge(x,y);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}