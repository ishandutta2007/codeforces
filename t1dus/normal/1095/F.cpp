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

int n,m;
vector<pii> adj[200005];
int a[200005];
set<pii> mset;
bitset<200005> vis;
int mn;
priority_queue<pii,vector<pii>,greater<pii> > pq;

signed main(){
  cin >> n >> m;
  FOR(i,1,n+1) cin >> a[i];
  REP(i,m){
    int u,v,w; cin >> u >> v >> w;
    adj[u].pb({w,v});
    adj[v].pb({w,u});
  }
  mn = a[1];
  vis[1] = 1;
  for(auto x:adj[1]){
    pq.push(x);
  }
  FOR(i,2,n+1){
    mset.insert({a[i],i});
  }
  int ans = 0;
  int cnt = 0;
  while(cnt != n-1){
    int u,cost;
    if(pq.size()){
      u = pq.top().S;
      cost = pq.top().F;
    }
    else{
      u = 0;
      cost = 10000000000001;
    }
    auto lol = *mset.begin();
    int v = lol.S;
    int cost2 = lol.F;
    cost2 += mn;
    if(cost2 < cost){
      // cout << vis[v] << " " << a[v] << " " << v << " " << n << " " << cnt << endl;
      mset.erase(mset.begin());
      if(vis[v]) continue;
      vis[v] = true;
      ans += cost2;
      remin(mn,a[v]);
      for(auto x:adj[v]){
        if(!vis[x.S]) pq.push(x);
      }
    }
    else{
      pq.pop();
      if(vis[u]) continue;
      vis[u] = true;
      ans += cost;
      remin(mn,a[u]);
      for(auto x:adj[u]){
        if(!vis[x.S]) pq.push(x);
      }
    }
    cnt ++;
  }
  cout << ans << endl;
}