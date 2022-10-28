#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int M = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

vector<int64_t> edges;
vector<int> adj[N];
int sub[N];
int n;

void dfs(int u, int p) {
  sub[u] = 1;
  for (int c : adj[u]){
    if (c != p) {
      dfs(c, u);
      sub[u] += sub[c];
      edges.push_back(1LL * sub[c] * (n - sub[c]));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    fill(adj, adj + n + 1, vector<int>());
    edges.clear();

    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, 0);

    int m;
    cin >> m;
    vector<int> p(m);
    for (auto& i : p) {
      cin >> i;
    }

    while (m < n - 1) {
      p.push_back(1);
      ++m;
    }

    sort(p.begin(), p.end());
    sort(edges.begin(), edges.end());

    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
      ans = add(ans, mul(edges[i] % M, p[i]));
    }

    int last = edges[n - 2] % M;
    for (int i = n - 2; i < m; ++i) {
      last = mul(last, p[i]);
    }
    ans = add(ans, last);
    cout << ans << "\n";
  }
}