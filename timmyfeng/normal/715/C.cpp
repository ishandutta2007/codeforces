#include <bits/stdc++.h>
using namespace std;

int M;
struct mint {

  int val = 0;

  mint() {}

  mint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  mint operator+=(mint oth) {
    val += oth.val;
    val -= (val >= M) ? M : 0;
    return *this;
  }

  mint operator-=(mint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
    return *this;
  }

  mint operator*=(mint oth) {
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

  mint operator-() {
    mint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return mint(a) += b;
  }

  friend mint operator-(mint a, mint b) {
    return mint(a) -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.val == b.val;
  }

  friend bool operator!=(mint a, mint b) {
    return a.val != b.val;
  }

  friend ostream& operator<<(ostream &out, mint a) {
    out << a.val;
    return out;
  }

  friend mint pow(mint b, long long e) {
    mint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

  friend mint inv(mint a) {
    if (a.val <= 1) {
      return 1;
    }
    return -(M / a.val) * inv((mint) (M % a.val));
  }

};

tuple<int, int, int> gcd(int a, int b) {
	if (!b) {
		return {1, 0, a};
	} else {
		auto [x, y, g] = gcd(b, a % b);
		return {y, x - (a / b) * y, g};
	}
}
 
int mod_inv(int a) {
	return (get<0>(gcd(a, M)) % M + M) % M;
}

const int N = 100000;

vector<array<int, 2>> adj[N];
bool visited[N];
int sub[N];

mint coeff_u, coeff_d, inv10;
mint down[N];
mint up[N];

map<int, int> freq;
long long ans;

void dfs_sub(int u, int p) {
  sub[u] = 1;
  for (auto [c, w] : adj[u]) {
    if (!visited[c] && c != p) {
      dfs_sub(c, u);
      sub[u] += sub[c];
    }
  }
}

int dfs_find(int u, int p, int n) {
  for (auto [c, w] : adj[u]) {
    if (!visited[c] && c != p && sub[c] * 2 > n) {
      return dfs_find(c, u, n);
    }
  }
  return u;
}

void dfs_dist(int u, int p) {
  for (auto [c, w] : adj[u]) {
    if (!visited[c] && c != p) {
      down[c] = down[u] + coeff_d * w;
      up[c] = up[u] + coeff_u * w;
      coeff_u *= inv10;
      coeff_d *= 10;

      dfs_dist(c, u);
      coeff_d *= inv10;
      coeff_u *= 10;
    }
  }
}

void dfs_add(int u, int p, int k) {
  freq[down[u].val] += k;
  for (auto [c, w] : adj[u]) {
    if (!visited[c] && c != p) {
      dfs_add(c, u, k);
    }
  }
}

void dfs_update(int u, int p) {
  ans += freq[(-up[u]).val];
  for (auto [c, w] : adj[u]) {
    if (!visited[c] && c != p) {
      dfs_update(c, u);
    }
  }
}

void solve(int u) {
  dfs_sub(u, -1);
  u = dfs_find(u, -1, sub[u]);

  up[u] = 0;
  down[u] = 0;
  coeff_d = 1;
  coeff_u = inv10;
  dfs_dist(u, -1);

  dfs_add(u, -1, 1);
  ans += freq[0] - 1;

  for (auto [c, w] : adj[u]) {
    if (!visited[c]) {
      dfs_add(c, u, -1);
      dfs_update(c, u);
      dfs_add(c, u, 1);
    }
  }
  freq.clear();

  visited[u] = true;
  for (auto [c, w] : adj[u]) {
    if (!visited[c]) {
      solve(c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> M;

  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  if (M == 1) {
    cout << (long long) n * (n - 1) << "\n";
    exit(0);
  }

  inv10 = mod_inv(10);

  solve(0);

  cout << ans << "\n";
}