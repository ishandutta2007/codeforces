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

int n,T;
int x[1000005],t[1000005],p[1000005],l[1000005],C[1000005],dp[1000005];
vector<pii> adj[1000005];
pii seg[4000015];

void upd(int pos,int val,int node = 1, int l = 0,int r = 1000001){
  // debug3(node,l,r);
  if(pos < l or pos > r) return;
  // debug3(node,l,r);
  seg[node].F += val;
  seg[node].S += val*pos;
  if(l != r){
    // cout << pos << "--\n";
    // debug3(node,l,r);
    upd(pos,val,2*node,l,(l+r)/2);
    upd(pos,val,2*node+1,(l+r)/2+1,r);
  }
}

int cook(int tl,int node = 1, int l = 0, int r = 1000001,int cur = 0){
  // cout << "-------------------------------------\n";
  // debug3(node,l,r)
  // debug2(tl,cur);
  // cout << "-------------------------------------\n";
  if(l == r){
    if(l == 0) return 0;
    if(r == 1000001) return cur;
    return cur+(tl/l);
  }
  if(seg[2*node].S >= tl) return cook(tl,2*node,l,(l+r)/2,cur);
  else return cook(tl-seg[2*node].S,2*node+1,(l+r)/2+1,r,cur+seg[2*node].F);
}

void dfs(int u,int tl = T){
  upd(t[u],x[u]);
  C[u] = cook(tl);
  // cout << u << " " << tl << " " << C[u] << endl;
  for(auto x: adj[u]){
    dfs(x.F,tl-2*x.S);
  }
  upd(t[u],-x[u]);
}

void calc(int u){
  vi v;
  for(auto x:adj[u]){
    calc(x.F);
    v.pb(dp[x.F]);
  }
  v.pb(0);
  v.pb(0);
  sort(all(v));
  if(u == 1) dp[u] = max(C[u],v[v.size()-1]);
  else dp[u] = max(C[u],v[v.size()-2]);
  // cout << u << " " << dp[u] << endl;
}

signed main(){
  cin >> n >> T;
  FOR(i,1,n+1) cin >> x[i];
  FOR(i,1,n+1) cin >> t[i];
  FOR(i,2,n+1){
    cin >> p[i] >> l[i];
    adj[p[i]].pb({i,l[i]});
  }
  dfs(1,T);
  calc(1);
  cout << dp[1] << endl;
}