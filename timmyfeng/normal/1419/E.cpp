#include <bits/stdc++.h>
using namespace std;

const int N = 10;

vector<vector<int>> ans[N];
set<int> adj[1 << N];
bool visited[1 << N];
vector<int> cur;

vector<int> divisors[1 << N];
vector<int> factors;
int n, m;

void dfs(int u) {
  visited[u] = true;
  cur.push_back(u);
  for (int i = 1; i < n; ++i) {
    adj[i].erase(u);
  }

  if (adj[u].empty()) {
    return;
  }

  int v = *adj[u].begin();
  for (auto c : adj[u]) {
    if (adj[c].size() < adj[v].size()) {
      v = c;
    }
  }

  dfs(v);
}

void process(int x) {
  int mask = 0;
  for (int i = 0; i < m; ++i) {
    if (x % factors[i] == 0) {
      mask ^= 1 << i;
    }
  }
  divisors[mask].push_back(x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < N; ++i) {
    n = 1 << i;
    for (int j = 1; j < n; ++j) {
      for (int k = 1; k < n; ++k) {
        if (j != k && (j & k) > 0) {
          adj[j].insert(k);
        }
      }
    }

    fill(visited, visited + n, false);
    for (int j = n - 1; j > 0; --j) {
      if (!visited[j]) {
        dfs(j);
        ans[i].push_back(cur);
        cur.clear();
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;

    int y = x;
    factors.clear();
    for (int i = 2; i * i <= y; ++i) {
      int cnt = 0;
      while (y % i == 0) {
        y /= i;
        ++cnt;
      }
      if (cnt > 0) {
        factors.push_back(i);
      }
    }
    if (y > 1) {
      factors.push_back(y);
    }
    m = factors.size();

    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        if (i > 1) {
          process(i);
        }
        if (i * i != x) {
          process(x / i);
        }
      }
    }

    if (m == 2 && divisors[3].size() > 1u) {
      y = divisors[3].back();
      divisors[3].pop_back();
      for (auto &i : ans[m]) {
        for (auto j : i) {
          for (auto k : divisors[j]) {
            cout << k << " ";
          }
          divisors[j].clear();
          if (j == 1) {
            cout << y << " ";
          }
        }
      }
      cout << "\n";
      cout << 0 << "\n";
    } else {
      for (auto &i : ans[m]) {
        for (auto j : i) {
          for (auto k : divisors[j]) {
            cout << k << " ";
          }
          divisors[j].clear();
        }
      }
      cout << "\n";
      cout << ans[m].size() - 1u << "\n";
    }
  }
}