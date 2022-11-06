#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto start = chrono::system_clock::now();
  auto seed = chrono::system_clock::now().time_since_epoch().count();
  mt19937 rng(seed);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  vector<int> w(N);
  vector<int> ds;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
      ds.push_back(A[i][j]);
    }
    cin >> w[i];
  }
  sort(ds.begin(), ds.end());
  ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      A[i][j] = lower_bound(ds.begin(), ds.end(), A[i][j]) - ds.begin();
    }
  }
  const int K = ds.size();
  vector<int> color(K);
  vector<int> best(1 << M, -1);
  vector<bool> used(K);

  int ans = numeric_limits<int>::max();

  constexpr int kTL = 2900;
  while (true) {
    for (int i = 0; i < K; ++i) {
      color[i] = rng() & 1;
    }
    fill(best.begin(), best.end(), -1);
    for (int i = 0; i < N; ++i) {
      int mask = 0;
      for (int j = 0; j < M; ++j) {
        mask |= color[A[i][j]] << j;
      }
      if (best[mask] == -1 || w[i] < w[best[mask]]) {
        best[mask] = i;
      }
    }
    for (int s = 0; s < (1 << M); ++s) {
      if (best[s] != -1 && best[s ^ ((1 << M) - 1)] != -1) {
        bool ok = true;
        for (int u : A[best[s]]) {
          if (used[u]) {
            ok = false;
          }
          used[u] = true;
        }
        for (int u : A[best[s ^ ((1 << M) - 1)]]) {
          if (used[u]) {
            ok = false;
          }
          used[u] = true;
        }
        for (int u : A[best[s]]) {
          used[u] = false;
        }
        for (int u : A[best[s ^ ((1 << M) - 1)]]) {
          used[u] = false;
        }
        if (ok) {
          ans = min(ans, w[best[s]] + w[best[s ^ ((1 << M) - 1)]]);
        }
      }
    }
    auto cur = chrono::system_clock::now();
    if (chrono::duration_cast<chrono::milliseconds>(cur - start).count() > kTL) {
      break;
    }
  }
  if (ans == numeric_limits<int>::max()) {
    ans = -1;
  }
  cout << ans << "\n";
}