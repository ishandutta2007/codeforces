#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(n < 4) {
      cout << "No" << endl;
      return 0;
    }
    vector<vi> g(n);
    rep(i,0,n-1) {
      int a,b;
      cin>>a>>b;
      --a,--b;
      g[a].eb(b);
      g[b].eb(a);
    }
    vi dist(n,-1);
    queue<int> bfs;
    rep(i,0,n) if(g[i].size() == 1) {
      bfs.push(i);
      dist[i] = 0;
    }
    while(!bfs.empty()) {
      int a = bfs.front();
      bfs.pop();
      for(int b:g[a]){
        if(dist[b] == -1) {
          dist[b] = dist[a]+1;
          bfs.push(b);
        }
      }
    }
    int mx = 0;
    rep(i,0,n) mx = max(dist[i], mx);

    int root = -1;
    rep(i,0,n) if(dist[i] == mx) {
      if(root != -1) {
        cout << "No" << endl;
        return 0;
      }
      root = i;
    }
    function<bool(int,int,int)> dfs = [&](int x, int p, int k) {
      if(k && g[x].size() < 4) return false;
      if(!k && g[x].size() > 1) return false;
      for(int y:g[x]) if(y != p)
        if(dfs(y,x,k-1) == false) return false;
      return true;
    };
    g[root].eb(-1);
    if(dfs(root, -1, k))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
}