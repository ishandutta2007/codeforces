#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
      cin >> B[i];
    }
    sort(B.begin(), B.end());
    vector<int> opt(M, -1);

    auto DivideConquer = [&](auto self, int l, int r, int tl, int tr) -> void {
      if (l > r) {
        return;
      }
      int m = (l + r) >> 1;
      int inv = 0, best = 1E9, p = -1;
      for (int i = tl; i <= tr; ++i) {
        if (inv < best) {
          best = inv;
          p = i;
        }
        if (i < N) {
          if (A[i] > B[m]) {
            inv++;
          } else if (A[i] < B[m]) {
            inv--;
          }
        }
      }
      opt[m] = p;
      self(self, l, m - 1, tl, p);
      self(self, m + 1, r, p, tr);
    };

    DivideConquer(DivideConquer, 0, M - 1, 0, N);
    vector<int> C;
    C.reserve(N + M);
    for (int i = 0, j = 0; i <= N; ++i) {
      while (j < M && opt[j] <= i) {
        C.push_back(B[j]);
        j++;
      }
      if (i < N) {
        C.push_back(A[i]);
      }
    }
    vector<int> ds(C.begin(), C.end());
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());

    int K = ds.size();
    vector<int> fw(K + 1);

    auto Update = [&](int p) {
      for (int i = p + 1; i <= K; i += i & -i) {
        fw[i]++;
      }
    };

    auto Query = [&](int p) {
      int res = 0;
      for (int i = p + 1; i > 0; i -= i & -i) {
        res += fw[i];
      }
      return res;
    };

    int64_t ans = 0;
    reverse(C.begin(), C.end());
    for (int x : C) {
      int p = lower_bound(ds.begin(), ds.end(), x) - ds.begin();
      ans += Query(p - 1);
      Update(p);
    }
    cout << ans << "\n";
  }
  return 0;
}