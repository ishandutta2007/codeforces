#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD=1e9+7;

const int N=200001;
int n, m, s, t;
vi adj[N];
bool seen[N];
int vis[N];
int prv[N];
vi path1, path2;

void dfs(int x, int TI){
  // cout << "dfs " << x << nl;
  vis[x]=TI;
  seen[x]=1;
  for(int k:adj[x]){
    if(seen[k] || k==s) continue;
    if(vis[k] && vis[k]!=TI){
      int u=k;
      while(u!=s){
        path1.pb(u);
        u=prv[u];
      }
      path2.pb(k);
      while(x!=s){
        path2.pb(x);
        x=prv[x];
      }
      t=k; 
      return;
    }
    else if(vis[k]) continue;
    prv[k]=x;
    dfs(k, TI);
    if(t) return;
  }
  seen[x]=0;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> s;

  rep(i,1,m){
    int u,v; cin >> u >> v;
    adj[u].pb(v);
  }

  int cnt=0;
  for(int k:adj[s]){
    if(vis[k]){
      path2={k};
      int u=k;
      while(u!=s){
        path1.pb(u);
        u=prv[u];
      }
      t=k;
      break;
    }
    prv[k]=s;
    dfs(k, ++cnt);
    if(t) break;
  }
  if(!t){
    cout << "Impossible";
    return 0;
  }

  cout << "Possible\n";
  reverse(all(path1));
  reverse(all(path2));
  cout << sz(path1)+1 << nl;
  cout << s << " ";
  for(int x:path1) cout << x << " ";
    cout << nl;
  cout << sz(path2)+1 << nl;
  cout << s << " ";
  for(int x:path2) cout << x << " ";
    cout << nl;
}