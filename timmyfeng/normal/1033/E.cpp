#include <bits/stdc++.h>
using namespace std;

const int N = 600;

vector<int> adj[N];
bool visited[N];
int color[N];
int n;

int query(vector<int> v) {
  if (v.size() <= 1) {
    return 0;
  }

  cout << "? " << v.size() << endl;
  for (auto i : v) {
    cout << i + 1 << " ";
  }
  cout << endl;

  int res;
  cin >> res;
  return res;
}

int find(int u, vector<int> v) {
  if (v.empty()) {
    return -1;
  } else if (v.size() == 1) {
    return query({u, v[0]}) == 1 ? v[0] : -1;
  }

  vector<int> l, r;
  for (int i = 0; i < (int) v.size(); ++i) {
    (i % 2 == 0 ? l : r).push_back(v[i]);
  }

  int without = query(v);
  v.push_back(u);
  if (query(v) == without) {
    return -1;
  }

  int res = find(u, l);
  if (res == -1) {
    res = find(u, r);
  }
  return res;
}

void dfs(int u) {
  visited[u] = true;
  while (true) {
    vector<int> unvisited;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        unvisited.push_back(i);
      }
    }

    int c = find(u, unvisited);
    if (c == -1) {
      break;
    }

    color[c] = 1 - color[u];
    adj[u].push_back(c);
    adj[c].push_back(u);
    dfs(c);
  }
}

vector<int> dfs_path(int u, int v, int p = -1) {
  if (u == v) {
    return {u};
  }
  for (auto c : adj[u]) {
    if (c != p) {
      vector<int> path = dfs_path(c, v, u);
      if (!path.empty()) {
        path.push_back(u);
        return path;
      }
    }
  }
  return {};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  dfs(0);

  for (int i = 0; i < 2; ++i) {
    vector<int> partition;
    for (int j = 0; j < n; ++j) {
      if (color[j] == i) {
        partition.push_back(j);
      }
    }

    int count = query(partition);
    if (count > 0) {
      while (!partition.empty()) {
      int u = partition.back();
      partition.pop_back();
      if (query(partition) < count) {
        for (auto v : partition) {
          if (query({u, v}) == 1) {
            vector<int> path = dfs_path(u, v);
            cout << "N " << path.size() << endl;
            for (auto i : path) {
              cout << i + 1 << " ";
            }
            cout << endl;
            exit(0);
          }
        }
      }
      }
      assert(false);
    }
  }

  cout << "Y " << count(color, color + n, 0) << endl;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}