/*input
3 4
1 2
2 3
3 2
3 1
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

int n,m;
vi adj[505];
int vis[505];

int check(int s){
	vis[s] = 1;
	int res = 0;
	for(auto x:adj[s]){
		if(vis[x] == 1) res ++;
		else if(vis[x] == 0)res += check(x);
	}
	vis[s] = 2;
	return res;
}

void solve(){
	cin >> n >> m;
	REP(i,m){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
	}
	FOR(i,1,n+1){
		FOR(j,1,n+1) vis[j] = 0;
		int tot = check(i);
		FOR(j,1,n+1){
			if(!vis[j]) tot += check(j);
		}
		// cout << i << " " << tot << endl;
		if(tot <= 1){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}