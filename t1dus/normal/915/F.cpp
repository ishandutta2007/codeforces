/*input
4
2 2 3 1
1 2
1 3
1 4
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

int n,ans = 0;
pii a[1000005],b[1000005];
vi adj[1000005];
int sz[1000005],par[1000005];

int find(int x){
	if( x == par[x] ) return x;
	return par[x]=find(par[x]);
}

void merge(int u,int v,int val){
	u = find(u);
	v = find(v);
	ans += sz[u]*sz[v]*val;
	if(sz[u] < sz[v]) swap(u,v);
	sz[u] += sz[v];
	par[v] = u;
}

void solve(){
	cin >> n;
	REP(i,n){
		cin >> a[i].F;
		a[i].S = i;
		b[i] = a[i];
	}
	sort(b,b+n);
	REP(i,n-1){
		int u,v; cin >> u >> v; u --; v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i,n){
		sz[i] = 1;
		par[i] = i;
	}
	REP(i,n){
		int val = b[i].F;
		int u = b[i].S;
		for(auto x:adj[u]){
			if(a[x] < a[u]){
				merge(u,x,val);
			}
		}
	}
	REP(i,n+1){
		sz[i] = 1;
		par[i] = i;
	}
	for(int i = n-1; i >= 0; i--){
		int val = b[i].F;
		int u = b[i].S;
		for(auto x:adj[u]){
			if(a[x] > a[u]){
				merge(u,x,-val);
			}
		}
	}
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}