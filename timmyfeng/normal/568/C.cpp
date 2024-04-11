#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 2;

vector<int> adj[N], jda[N];
int color[N], order[N], p;
bool visited[N];

void dfs_order(int u) {
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs_order(c);
    }
  }
  order[p--] = u;
}

void dfs_color(int u, int x) {
  color[u] = x;
  for (auto c : jda[u]) {
    if (color[c] == 0) {
      dfs_color(c, x);
    }
  }
}

string s, t, ans;
int n, m, l;

void solve(int index, bool greater) {
  if (index == n) {
    cout << ans << "\n";
    exit(0);
  }

  array<int, 2> memo{-1, -1};
  for (int i = 0; i < l; ++i) {
    if (!greater && i + 'a' < s[index]) {
      continue;
    }

    int u = 2 * index + (t[i] == 'C');
    adj[u ^ 1].push_back(u);
    jda[u].push_back(u ^ 1);

    if (memo[(t[i] == 'C')] == -1) {
      p = 2 * n - 1;
      fill(visited, visited + 2 * n, false);
      for (int j = 0; j < 2 * n; ++j) {
        if (!visited[j]) {
          dfs_order(j);
        }
      }

      int x = 0;
      fill(color, color + 2 * n, 0);
      for (int j = 0; j < 2 * n; ++j) {
        if (color[order[j]] == 0) {
          dfs_color(order[j], ++x);
        }
      }

      bool ok = true;
      for (int j = 0; j < n; ++j) {
        ok &= (color[2 * j] != color[2 * j + 1]);
      }
      memo[(t[i] == 'C')] = ok;
    }

    if (memo[(t[i] == 'C')] == 1) {
      ans += i + 'a';
      solve(index + 1, greater || i + 'a' > s[index]);
      ans.pop_back();
    }

    jda[u].pop_back();
    adj[u ^ 1].pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t >> n >> m;
  l = t.size();

  // evil exception case >:(
  if (count(t.begin(), t.end(), 'V') == 0) {
    for (int i = 0; i < n; ++i) {
      adj[2 * i].push_back(2 * i + 1);
      jda[2 * i + 1].push_back(2 * i);
    }
  } else if (count(t.begin(), t.end(), 'C') == 0) {
    for (int i = 0; i < n; ++i) {
      adj[2 * i + 1].push_back(2 * i);
      jda[2 * i].push_back(2 * i + 1);
    }
  }

  for (int i = 0; i < m; ++i) {
    int p1, p2;
    char t1, t2;
    cin >> p1 >> t1 >> p2 >> t2;
    int u = 2 * (p1 - 1) + (t1 == 'V');
    int v = 2 * (p2 - 1) + (t2 == 'C');
    adj[u ^ 1].push_back(v);
    adj[v ^ 1].push_back(u);
    jda[u].push_back(v ^ 1);
    jda[v].push_back(u ^ 1);
  }

  cin >> s;

  solve(0, false);

  cout << -1 << "\n";
}