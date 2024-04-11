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
    val -= (val >= M) ? M : 0;
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
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

using mint = modint<1000000007>;

const int N = 100000 + 1;
const int B = 400;

set<array<int, 2>> block[N];
map<int, mint> marbles[N];
array<int, 4> barrier[N];

void update(int r, int c, mint value) {
  marbles[r][c] = value;
  block[r / B].insert({c, r});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w, n;
  cin >> h >> w >> n;

  for (int i = 0; i < n; ++i) {
    for (auto &j : barrier[i]) {
      cin >> j;
    }
    --barrier[i][1];
  }
  sort(barrier, barrier + n);

  for (int i = 0; i < w; ++i) {
    update(n, i, 1);
  }
  barrier[n][0] = h + 1;

  for (int i = n - 1; i >= 0; --i) {
    auto [u, l, r, s] = barrier[i];
    int t = upper_bound(barrier, barrier + n + 1, array<int, 4>{u + s, w}) - barrier;

    mint sum = 0;
    for (int j = (i + 1) / B; j <= (t - 1) / B; ++j) {
      auto check = block[j].lower_bound({l, 0});
      if (check != block[j].end() && (*check)[0] < r) {
        for (int k = max(i + 1, j * B); k < min(t, (j + 1) * B); ++k) {
          auto it = marbles[k].lower_bound(l);
          while (it != marbles[k].end() && it->first < r) {
            sum += it->second;
            block[j].erase({it->first, k});
            marbles[k].erase(it);
            it = marbles[k].lower_bound(l);
          }
        }
      }
    }

    if (sum != 0) {
      if (l == 0) {
        update(i, r, sum * 2);
      } else if (r == w) {
        update(i, l - 1, sum * 2);
      } else {
        update(i, l - 1, sum);
        update(i, r, sum);
      }
    }
  }

  mint ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (auto [a, b] : marbles[i]) {
      ans += b;
    }
  }

  cout << ans.val << "\n";
}