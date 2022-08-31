/*input
1
2
1
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

int n,s,p;
vector<pii> g[200005];
vi adj[200005];
int comp[200005],a[200005],c[200005],cost[200005];
bitset<500005> vis;
int cmp;
stack<int> st;

void dfs(int u){
    vis[u] = 1;
    for(auto x:g[u]){
        if(x.S == 0 and (!vis[x.F])) dfs(x.F);
    }
    st.push(u);
}

void kosa(int u){
    // cout << u << endl;
    vis[u] = 1;
    comp[u] = cmp;
    remin(cost[cmp],c[u]);
    for(auto x:g[u]){
        if(x.S == 1 and (!vis[x.F])) kosa(x.F);
    }
}

signed main(){

	int t; t = 1;
	WL(t){
		cin >> n;
		FOR(i,1,n+1) cin >> c[i];
		FOR(i,1,n+1){
			cin >> a[i];
			if(a[i] == i) continue;
			g[i].pb({a[i],0});
			g[a[i]].pb({i,1});
		}
		vis.reset();
		cost[0] = 1000000000;
		FOR(i,1,n+1){
	        if(!vis[i]) dfs(i);
			cost[i] = 1000000000;
	    }
	    vis.reset();
	    cmp = 0;
	    while(!st.empty()){
		    int u = st.top(); st.pop();
		    if(vis[u]) continue;
		    kosa(u);
		    cmp ++;
		}
		FOR(i,1,n+1){
		    for(auto x:g[i]){
		        if(x.S == 0 and comp[x.F] != comp[i]) adj[comp[i]].pb(comp[x.F]);
		    }
		}
		// REP(i,cmp){
		// 	cout << i << " " << cost[i] << endl;
		// }
		int ans = 0;
		REP(i,cmp){
			if(adj[i].size() == 0) ans += cost[i];
		}
		cout << ans << endl;
	}
}