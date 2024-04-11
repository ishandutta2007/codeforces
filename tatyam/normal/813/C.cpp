#include <bits/stdc++.h>
using namespace std;
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
const int INF = 0x3fffffff;
 
vector<int> bfs(const vector<vector<int>>& g, int s){
  vector<int> d(g.size(), INF);
  queue<int> q;
  d[s] = 0;
  q.push(s);
  while(q.size()){
    int at = q.front();
    q.pop();
    for(int i : g[at]) if(chmin(d[i], d[at] + 1)) q.push(i);
  }
  return d;
}
int main(){
  int n, u, v = 1;
  cin >> n >> u;
  u--; v--;
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> d_taka = bfs(g, u), d_aoki = bfs(g, v);
  int ans = 0;
  for(int i = 0; i < n; i++) if(d_taka[i] < d_aoki[i]) chmax(ans, d_aoki[i]);
  cout << ans * 2 << endl;
}