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

using mint = modint<1'000'000'007>;
const int N = 100'000;
const int K = 200 + 1;

mint ways[N][K];
mint ways_new[K];

mint choose[K][K];
mint stirling[K][K];

vector<int> adj[N];
int sub[N];
mint ans;
int k;

void dfs(int u, int p) {
  ways[u][0] = 1;

  for (auto c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      for (int i = 0; i <= min(k, sub[c]); ++i) {
        ans -= ways[c][i] * stirling[k][i];
      }

      fill(ways_new, ways_new + min(k, sub[u] + sub[c]) + 1, 0);
      for (int i = 0; i <= min(sub[u], k); ++i) {
        for (int j = 0; j <= min(sub[c], k - i); ++j) {
          ways_new[i + j] += ways[u][i] * ways[c][j] * choose[i + j][i];
        }
      }

      sub[u] += sub[c];
      copy(ways_new, ways_new + min(k, sub[u]) + 1, ways[u]);
    }
  }
  ++sub[u];

  for (int i = k; i >= 0; --i) {
    ways[u][i] *= 2;
    ans += ways[u][i] * stirling[k][i];
    if (i > 0) {
      ways[u][i] += 2 * i * ways[u][i - 1];
    }
  }
  --ways[u][1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;

  choose[0][0] = 1;
  stirling[0][0] = 1;

  for (int i = 1; i <= k; ++i) {
    choose[i][0] = 1;
    choose[i][i] = 1;
    for (int j = 1; j <= i; ++j) {
      stirling[i][j] = j * stirling[i - 1][j] + stirling[i - 1][j - 1];
      if (j < i) {
        choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
      }
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);

  cout << ans.val << "\n";
}