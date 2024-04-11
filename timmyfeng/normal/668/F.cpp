#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int value;

  mint() : value(0) {}

  template <class T>
  mint(T x) {
    value = x % M;
    if (value < 0) {
      value += M;
    }
  }

  mint & operator++() {
    if (++value == M) {
      value = 0;
    }
    return *this;
  }

  mint & operator--() {
    if (--value == -1) {
      value = M - 1;
    }
    return *this;
  }

  mint operator++(int) {
    mint res = *this;
    ++*this;
    return res;
  }

  mint operator--(int) {
    mint res = *this;
    --*this;
    return res;
  }

  mint & operator+=(mint oth) {
    value += oth.value;
    if (value >= M) {
      value -= M;
    }
    return *this;
  }

  mint & operator-=(mint oth) {
    value -= oth.value;
    if (value < 0) {
      value += M;
    }
    return *this;
  }

  mint & operator*=(mint oth) {
    value = (long long) value * oth.value % M;
    return *this;
  }

  mint operator+() const {
    return *this;
  }

  mint operator-() const {
    return mint() - *this;
  }

  mint pow(long long e = M - 2) const {
    mint res = 1, b = *this;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return a += b;
  }

  friend mint operator-(mint a, mint b) {
    return a -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.value == b.value;
  }

  friend bool operator!=(mint a, mint b) {
    return a.value != b.value;
  }

  friend ostream & operator<<(ostream &out, mint a) {
    out << a.value;
    return out;
  }

};

const int N = 10000 + 1;

vector<array<int, 2>> edge[N];
vector<int> clique[N], adj[N];

bool unite(vector<int> &dsu, int u, int a, int b) {
  a = dsu[find(clique[u].begin(), clique[u].end(), a) - clique[u].begin()];
  b = dsu[find(clique[u].begin(), clique[u].end(), b) - clique[u].begin()];

  if (a == b) {
    return false;
  }

  if (a > b) {
    swap(a, b);
  }

  for (auto &c : dsu) {
    if (c == b) {
      c = a;
    }
  }
  return true;
}

map<vector<int>, mint> dfs(int u) {
  map<vector<int>, mint> ways;
  for (int i = 0; i < (1 << edge[u].size()); ++i) {
    vector<int> dsu = clique[u];

    bool ok = true;
    for (int j = 0; j < (int) edge[u].size() && ok; ++j) {
      if ((i & (1 << j)) > 0) {
        auto [a, b] = edge[u][j];
        ok &= unite(dsu, u, a, b);
      }
    }

    if (ok) {
      ++ways[dsu];
    }
  }

  for (auto c : adj[u]) {
    map<vector<int>, mint> child = dfs(c), new_ways;
    for (auto &[dsu_c, w_c] : child) {
      if (dsu_c.back() == clique[c].back()) {
        continue;
      }

      for (auto &[dsu_u, w_u] : ways) {
        bool ok = true;
        vector<int> dsu = dsu_u;
        for (int i = 0; i < (int) dsu_c.size() - 1 && ok; ++i) {
          for (int j = i + 1; j < (int) dsu_c.size() - 1; ++j) {
            if (dsu_c[i] == dsu_c[j]) {
              ok &= unite(dsu, u, clique[c][i], clique[c][j]);
              break;
            }
          }
        }

        if (ok) {
          new_ways[dsu] += w_u * w_c;
        }
      }
    }
    swap(ways, new_ways);
  }

  return ways;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  clique[k].resize(k);
  iota(clique[k].begin(), clique[k].end(), 1);
  for (int i = 1; i <= k; ++i) {
    for (int j = i + 1; j <= k; ++j) {
      edge[k].push_back({i, j});
    }
  }

  for (int i = k + 1; i <= n; ++i) {
    clique[i].resize(k);
    for (auto &j : clique[i]) {
      cin >> j;
      edge[i].push_back({j, i});
    }
    sort(clique[i].begin(), clique[i].end());
    clique[i].push_back(i);

    for (int j = k; j < i; ++j) {
      int r = 0;
      for (int l = 0; l < k; ++l) {
        for ( ; r < (int) clique[j].size() && clique[i][l] != clique[j][r]; ++r);
      }

      if (r < (int) clique[j].size()) {
        adj[j].push_back(i);
        break;
      }
    }
  }

  cout << dfs(k)[vector<int>(k, 1)] << "\n";
}