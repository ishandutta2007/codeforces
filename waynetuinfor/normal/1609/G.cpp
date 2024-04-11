#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int64_t> A(N);
  vector<int64_t> B(M), Bd(M - 1);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }
  for (int i = 0; i < M - 1; ++i) {
    Bd[i] = B[i + 1] - B[i];
  }

  int sz = 1, bit = 0;
  while (sz <= M) {
    sz <<= 1;
    bit++;
  }
  vector<int64_t> fw(sz);

  auto Update = [&](int p, int64_t v) {
    for (int i = p + 1; i < sz; i += i & -i) {
      fw[i] += v;
    }
  };

  for (int i = 0; i < M - 1; ++i) {
    Update(i, (i > 0 ? Bd[i] - Bd[i - 1] : Bd[i]));
  }

  auto FirstGreater = [&](int64_t v) {
    int p = 0;
    for (int d = bit - 1; d >= 0; --d) {
      if (fw[p + (1 << d)] < v) {
        v -= fw[p + (1 << d)];
        p += (1 << d);
      }
    }
    return p;
  };

  vector<int64_t> tree(M * 4);
  vector<int64_t> itag(M * 4);
  vector<int64_t> stag(M * 4);

  auto Build = [&]() {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (r - l == 1) {
        tree[o] = B[l];
        return;
      }
      int m = (l + r) >> 1;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = tree[o * 2 + 1] + tree[o * 2 + 2];
    };

    return dfs(dfs, 0, M);
  };

  Build();

  auto UpdateSum = [&](int ql, int qr, int d, int64_t s) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (l >= qr || ql >= r) return;
      if (l >= ql && r <= qr) {
        tree[o] += 1LL * (r - l) * (l + r - 1) / 2 * d;
        tree[o] += (r - l) * s;
        stag[o] += s;
        itag[o] += d;
        return;
      }
      int m = (l + r) >> 1;
      tree[o * 2 + 1] += (m - l) * stag[o];
      tree[o * 2 + 1] += 1LL * (m - l) * (l + m - 1) / 2 * itag[o];
      stag[o * 2 + 1] += stag[o];
      itag[o * 2 + 1] += itag[o];
      tree[o * 2 + 2] += (r - m) * stag[o];
      tree[o * 2 + 2] += 1LL * (r - m) * (m + r - 1) / 2 * itag[o];
      stag[o * 2 + 2] += stag[o];
      itag[o * 2 + 2] += itag[o];
      itag[o] = stag[o] = 0;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = tree[o * 2 + 1] + tree[o * 2 + 2];
    };

    return dfs(dfs, 0, M);
  };

  auto QuerySum = [&](int ql, int qr) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> int64_t {
      if (l >= qr || ql >= r) return 0;
      if (l >= ql && r <= qr) return tree[o];
      int m = (l + r) >> 1;
      tree[o * 2 + 1] += (m - l) * stag[o];
      tree[o * 2 + 1] += 1LL * (m - l) * (l + m - 1) / 2 * itag[o];
      stag[o * 2 + 1] += stag[o];
      itag[o * 2 + 1] += itag[o];
      tree[o * 2 + 2] += (r - m) * stag[o];
      tree[o * 2 + 2] += 1LL * (r - m) * (m + r - 1) / 2 * itag[o];
      stag[o * 2 + 2] += stag[o];
      itag[o * 2 + 2] += itag[o];
      itag[o] = stag[o] = 0;
      return dfs(dfs, l, m, o * 2 + 1) + dfs(dfs, m, r, o * 2 + 2);
    };

    return dfs(dfs, 0, M);
  };

  while (Q--) {
    int type, k, d;
    cin >> type >> k >> d;
    if (type == 1) {
      for (int i = N - k; i < N; ++i) {
        A[i] += d * (i - (N - k) + 1);
      }
    } else {
      // Bd[(M - k) - 1] ~ Bd[M - 2] += d
      if (k < M) {
        Update(M - k - 1, d);
      } else {
        Update(0, d);
      }
      UpdateSum(M - k, M, d, -1LL * (M - k - 1) * d);
    }
    int y = 0;
    int64_t ans = 0;
    for (int i = 0; i + 1 < N; ++i) {
      int64_t diff = A[i + 1] - A[i];
      int to = min(M - 1, FirstGreater(diff));
      assert(to >= y);
      ans += A[i] * (to - y + 1);
      ans += QuerySum(y, to + 1);
      y = to;
    }
    ans += A[N - 1] * (M - y);
    ans += QuerySum(y, M);
    cout << ans << "\n";
  }
  return 0;
}