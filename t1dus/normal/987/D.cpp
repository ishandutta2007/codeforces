/*input
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5
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

int n,m,k,s;
int a[100005];
vi adj[100005];

int dist[100005][105];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> s;
	FOR(i,1,n+1) cin >> a[i];
	REP(i,m){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	queue<pii> q;
	REP(i,100005) REP(j,105) dist[i][j] = INF;
	FOR(i,1,n+1){
		dist[i][a[i]] = 0;
		q.push({i,a[i]});
	}
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		for(auto x:adj[u.F]){
			if(dist[x][u.S] > dist[u.F][u.S]+1){
				dist[x][u.S] = dist[u.F][u.S]+1;
				q.push({x,u.S});
			}
		}
	}
	FOR(i,1,n+1){
		int ans = 0;
		vi v;
		FOR(j,1,k+1) v.pb(dist[i][j]);
		sort(all(v));
		REP(j,s) ans += v[j];
		cout << ans << " ";
	}
}