#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i] >> y[i];
  }

  constexpr int kB = 500;
  vector<int> big(M);
  vector<vector<int>> small(kB);
  vector<int> start(N, -1);
  for (int i = 1; i < kB; ++i) {
    small[i].resize(i);
  }
  int s = 0;
  for (int i = 0; i < M; ++i) {
    int o, k;
    cin >> o >> k;
    k--;
    if (o == 1) {
      if (x[k] + y[k] < kB) {
        s++;
        int g = x[k] + y[k];
        small[g][(i + x[k]) % g]++;
        small[g][(i + x[k] + y[k]) % g]--;
      } else {
        for (int j = i; j < M; j += x[k] + y[k]) {
          if (j + x[k] < M) {
            big[j + x[k]]++;
          }
          if (j + x[k] + y[k] < M) {
            big[j + x[k] + y[k]]--;
          }
        }
      }
      start[k] = i;
    } else {
      assert(start[k] != -1);
      if (x[k] + y[k] < kB) {
        int g = x[k] + y[k];
        small[g][(start[k] + x[k]) % g]--;
        small[g][(start[k] + x[k] + y[k]) % g]++;
        int diff = (i - start[k]) % g;
        if ((diff == 0 || diff >= x[k]) && (start[k] + x[k]) % g != i % g) s--;
      } else {
        for (int j = start[k]; j < M; j += x[k] + y[k]) {
          if (j + x[k] < i) {
            s--;
          } else if (j + x[k] < M) {
            big[j + x[k]]--;
          }
          if (j + x[k] + y[k] < i) {
            s++;
          } else if (j + x[k] + y[k] < M) {
            big[j + x[k] + y[k]]++;
          }
        }
      }
      start[k] = -1;
    }
    s += big[i];
    for (int j = 1; j < kB; ++j) {
      s += small[j][i % j];
    }
    cout << s << "\n";
  }
}