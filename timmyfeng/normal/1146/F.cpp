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
const int N = 200'000;

mint prefix[N];
mint suffix[N];

mint choose[N];
mint ways[N];

vector<int> adj[N];

void dfs(int u) {
  choose[u] = 1;
  ways[u] = 1;

  if (adj[u].empty()) {
    return;
  }

  for (auto c : adj[u]) {
    dfs(c);
    ways[u] *= ways[c];
    choose[u] *= choose[c] + ways[c];
  }
  choose[u] -= ways[u];

  int sub = adj[u].size();
  for (int i = 0; i < sub; ++i) {
    prefix[i] = ways[adj[u][i]];
    suffix[i] = ways[adj[u][i]];
  }
  for (int i = 1; i < sub; ++i) {
    prefix[i] *= prefix[i - 1];
    suffix[sub - 1 - i] *= suffix[sub - i];
  }

  ways[u] += choose[u];
  for (int i = 0; i < sub; ++i) {
    mint cur = choose[adj[u][i]];
    if (i > 0) {
      cur *= prefix[i - 1];
    }
    if (i < sub - 1) {
      cur *= suffix[i + 1];
    }
    ways[u] -= cur;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    adj[p - 1].push_back(i);
  }

  dfs(0);

  cout << ways[0].val << "\n";
}