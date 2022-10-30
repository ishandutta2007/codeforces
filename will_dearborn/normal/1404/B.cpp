#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

vector<int> bfs(const vvi& graph, int start) {
  vector<int> distance(graph.size(), 1e9);
  distance[start] = 0;
  queue<int> q;  //      ,       ,          
  q.push(start); // start,a,b..
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    for (auto to : graph[from]) {
      if (distance[to] > distance[from] + 1) {
        distance[to] = distance[from] + 1;
        q.push(to);
      }
    }
  }
  return distance;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a; --b;
    vvi g(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vi dista = bfs(g, a);
    bool win = 0;
    if (dista[b] <= da || da * 2 >= db) win = 1;
    else {
      pii ma(0, a);
      for (int i = 0; i < n; ++i) ma = max(ma, pii(dista[i], i));
      auto d = bfs(g, ma.second);
      int D = 0;
      for (int i = 0; i < n; ++i) D = max(D, d[i]);
      if (da * 2 >= D) win = 1;
    }
    if (win) cout << "Alice\n";
    else cout << "Bob\n";
  }
  return 0;
}