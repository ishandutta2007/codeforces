#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  modint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  modint operator+=(modint oth) {
    val += oth.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    if (val < 0) {
      val += M;
    }
    return *this;
  }

  modint operator*=(modint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }

  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }

  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }

  modint operator-() {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  int mod() {
    return M;
  }

  modint pow(int e) {
    modint base = val;
    modint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= base;
      }
      base *= base;
      e /= 2;
    }
    return res;
  }

  modint inv() {
    return pow(M - 2);
  }

  friend modint operator+(modint a, modint b) {
    return modint(a) += b;
  }

  friend modint operator-(modint a, modint b) {
    return modint(a) -= b;
  }

  friend modint operator*(modint a, modint b) {
    return modint(a) *= b;
  }

  friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }

  friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

};

using mint = modint<998'244'353>;
const int N = 1'500 + 1;

array<int, 2> edge[N * N];
int count_edge[N];
int root[N];
int sub[N];

mint ways[N][N];
mint ways_new[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      if (i < j) {
        edge[a - 1] = {i, j};
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    ways[i][1] = 1;
    root[i] = i;
    sub[i] = 1;
  }

  for (int i = 0; i < n * (n - 1) / 2; ++i) {
    int u = root[edge[i][0]];
    int v = root[edge[i][1]];

    if (u != v) {
      fill(ways_new, ways_new + sub[u] + sub[v] + 1, 0);
      for (int j = 0; j <= sub[u]; ++j) {
        for (int k = 0; k <= sub[v]; ++k) {
          ways_new[j + k] += ways[u][j] * ways[v][k];
        }
      }
      copy(ways_new, ways_new + sub[u] + sub[v] + 1, ways[u]);

      sub[u] += sub[v]; 
      count_edge[u] += count_edge[v];
      for (int i = 0; i < n; ++i) {
        if (root[i] == v) {
          root[i] = u;
        }
      }
    }

    ways[u][1] += (++count_edge[u] == sub[u] * (sub[u] - 1) / 2);
  }

  for (int i = 1; i <= n; ++i) {
    cout << ways[root[0]][i].val << " ";
  }
  cout << "\n";
}