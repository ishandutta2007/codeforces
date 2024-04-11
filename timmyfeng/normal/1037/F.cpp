#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int val = 0;

  mint() {}

  mint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

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

  friend mint pow(mint b, long long e = M - 2) {
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

};

const int N = 1000000 + 1;
const int L = __lg(N) + 1;

array<int, 2> sparse[L][N];
mint segments[N];
int a[N];

array<int, 2> query(int l, int r) {
  int log = __lg(r - l + 1);
  return max(sparse[log][l], sparse[log][r + 1 - (1 << log)]);
}

mint solve(int l, int r) {
  if (l > r) {
    return 0;
  }
  auto [value, m] = query(l, r);
  mint coeff = segments[r - l + 1] - segments[m - l] - segments[r - m];
  return solve(l, m - 1) + value * coeff + solve(m + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i <= __lg(n); ++i) {
    for (int j = 0; j + (1 << i) <= n; ++j) {
      if (i == 0) {
        sparse[i][j] = {a[j], j};
      } else {
        sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  int nxt = k, delta = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == nxt) {
      nxt += k - 1;
      ++delta;
    }
    segments[i] = segments[i - 1] + delta;
  }

  cout << solve(0, n - 1) << "\n";
}