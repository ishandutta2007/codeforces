#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 1;

vector<int> a[N];
long long all[N];
int length[N];
int t;

long long max_sum[N][N];
long long ans;

void solve(const vector<array<int, 3>> &queries, int l, int r, int size) {
  vector<array<int, 3>> left, right;
  int m = (l + r) / 2;

  for (auto [a, b, i] : queries) {
    if (a <= l && r <= b) {
      ++size;
      for (int j = 0; j <= t; ++j) {
        max_sum[size][j] = max_sum[size - 1][j];
        if (j >= length[i]) {
          max_sum[size][j] = max(max_sum[size][j], max_sum[size - 1][j - length[i]] + all[i]);
        }
      }
    } else {
      if (a <= m) {
        left.push_back({a, b, i});
      }
      if (b > m) {
        right.push_back({a, b, i});
      }
    }
  }

  if (l == r) {
    long long sum = 0;
    for (int i = 0; i < min(length[l], t); ++i) {
      sum += a[l][i];
      ans = max(ans, sum + max_sum[size][t - i - 1]);
    }
  } else {
    solve(left, l, m, size);
    solve(right, m + 1, r, size);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> t;

  for (int i = 0; i < n; ++i) {
    cin >> length[i];
    a[i].resize(length[i]);
    for (auto &j : a[i]) {
      cin >> j;
    }
    all[i] = accumulate(a[i].begin(), a[i].end(), 0LL);
  }

  vector<array<int, 3>> queries;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      queries.push_back({0, i - 1, i});
    }
    if (i < n - 1) {
      queries.push_back({i + 1, n - 1, i});
    }
  }

  solve(queries, 0, n - 1, 0);

  cout << ans << "\n";
}