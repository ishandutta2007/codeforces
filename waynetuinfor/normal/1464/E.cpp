#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }

  vector<int> gv(N, -1);
  auto Grundy = [&](auto self, int x) -> int {
    if (gv[x] != -1) {
      return gv[x];
    }
    set<int> s;
    for (int u : g[x]) {
      s.insert(self(self, u));
    }
    gv[x] = 0;
    while (s.count(gv[x])) gv[x]++;
    return gv[x];
  };

  for (int i = 0; i < N; ++i) {
    gv[i] = Grundy(Grundy, i);
    assert(gv[i] <= 500);
  }

  int K = *max_element(gv.begin(), gv.end()) + 1;
  while (__builtin_popcount(K) != 1) K++;
  vector<int> cnt(K);
  for (int u : gv) cnt[u]++;

  constexpr int kP = 998244353;

  auto fpow = [&](int a, int n) {
    int res = 1;
    while (n > 0) {
      if (n & 1) res = 1LL * res * a % kP;
      a = 1LL * a * a % kP;
      n >>= 1;
    }
    return res;
  };

  const int kI = fpow(N + 1, kP - 2);

  vector<vector<int>> D(K, vector<int>(K));
  vector<int> value(K);
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      D[i][i ^ j] += 1LL * cnt[j] * kI % kP;
      D[i][i ^ j] %= kP;
    }
    D[i][i] += kP - 1;
    D[i][i] %= kP;
    if (i > 0) {
      value[i] = (kP - kI) % kP;
    }
  }
  for (int i = 0; i < K; ++i) {
    int pivot = -1;
    for (int j = i; j < K; ++j) {
      if (D[j][i] != 0) {
        pivot = j;
        break;
      }
    }
    assert(pivot != -1);
    swap(D[i], D[pivot]);
    swap(value[i], value[pivot]);
    int inv = fpow(D[i][i], kP - 2);
    for (int j = i + 1; j < K; ++j) {
      int r = 1LL * D[j][i] * inv % kP;
      for (int k = 0; k < K; ++k) {
        D[j][k] += kP - 1LL * r * D[i][k] % kP;
        D[j][k] %= kP;
      }
      value[j] += kP - 1LL * r * value[i] % kP;
      value[j] %= kP;
    }
  }
  vector<int> x(K);
  for (int i = K - 1; i >= 0; --i) {
    int s = 0;
    for (int j = i + 1; j < K; ++j) {
      s += 1LL * x[j] * D[i][j] % kP;
      s %= kP;
    }
    s = (value[i] + kP - s) % kP;
    x[i] = 1LL * s * fpow(D[i][i], kP - 2) % kP;
  }
  cout << x[0] << "\n";
  return 0;
}