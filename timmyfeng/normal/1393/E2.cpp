#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 1e6 + 1;
const int M = 1e9 + 7;
const int H = 1;

mt19937 rng(uint64_t(new char));

int rand_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int mod_inv(int a) {
  return mod_pow(a, M - 2);
}

int pow_base[H][K];
int inv_base[H][K];
int base[H];

void init_hash() {
  for (int i = 0; i < H; ++i) {
    base[i] = rand_int(137, M - 1);
    int inv = mod_inv(base[i]);
    pow_base[i][0] = 1;
    inv_base[i][0] = 1;
    for (int j = 1; j < K; ++j) {
      pow_base[i][j] = mul(pow_base[i][j - 1], base[i]);
      inv_base[i][j] = mul(inv_base[i][j - 1], inv);
    }
  }
}

struct rolling_hash {

  vector<int> pre[H];

  void build(const string& s) {
    int n = s.size();
    for (int i = 0; i < H; ++i) {
      pre[i].resize(n + 1);
      for (int j = 0; j < n; ++j) {
        pre[i][j + 1] = add(pre[i][j], mul(s[j], pow_base[i][j]));
      }
    }
  }

  array<int, H> query(int a, int b) {
    array<int, H> res;
    for (int i = 0; i < H; ++i) {
      res[i] = sub(pre[i][b + 1], pre[i][a]);
      res[i] = mul(res[i], inv_base[i][a]);
    }
    return res;
  }

} hsh[N];

vector<int> order[N];
vector<int> dp[N];
string s[N];

array<int, H> get(int a, int b, int c) {
  if (b < c) {
    auto left = hsh[a].query(0, b - 1);
    auto right = hsh[a].query(b + 1, c);
    for (int i = 0; i < H; ++i) {
      left[i] = add(left[i], mul(right[i], pow_base[i][b]));
    }
    return left;
  }
  return hsh[a].query(0, c - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init_hash();

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    int m = s[i].size();

    int pre = -1;
    vector<int> left;
    vector<int> right;
    for (int j = 0; j < m; ++j) {
      if (pre == -1) {
        pre = j;
      }
      if (j + 1 == m || s[i][j] != s[i][j + 1]) {
        for (int k = pre; k <= j; ++k) {
          if (j + 1 == m || s[i][j] > s[i][j + 1]) {
            left.push_back(k);
          } else {
            right.push_back(k);
          }
        }
        if (j + 1 == m) {
          left.push_back(m);
        }
        pre = -1;
      }
    }

    order[i] = left;
    while (!right.empty()) {
      order[i].push_back(right.back());
      right.pop_back();
    }

    hsh[i].build(s[i]);
    dp[i].resize(m + 1);
  }

  hsh[0].build(s[0]);
  dp[0].assign(1, 1);
  order[0].assign(1, 0);

  for (int i = 1; i <= n; ++i) {
    int k1 = s[i - 1].size();
    int k2 = s[i].size();

    int ptr = 0;
    for (int j = 0; j <= k2; ++j) {
      while (ptr <= k1) {
        int sz1 = k1 - (order[i - 1][ptr] < k1);
        int sz2 = k2 - (order[i][j] < k2);

        int lo = 0;
        int hi = min(sz1, sz2);
        while (lo <= hi) {
          int mid = (lo + hi) / 2;
          if (get(i - 1, order[i - 1][ptr], mid) == get(i, order[i][j], mid)) {
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        }

        if (hi == min(sz1, sz2)) {
          if (sz1 > sz2) {
            break;
          }
        } else if (s[i - 1][hi + (order[i - 1][ptr] <= hi)] > s[i][hi + (order[i][j] <= hi)]) {
          break;
        }

        ++ptr;
      }

      if (ptr > 0) {
        dp[i][j] = add(dp[i][j], dp[i - 1][ptr - 1]);
      }
    }

    for (int j = 1; j <= k2; ++j) {
      dp[i][j] = add(dp[i][j], dp[i][j - 1]);
    }
  }

  cout << dp[n][s[n].size()] << "\n";
}