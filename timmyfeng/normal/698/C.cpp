#include <bits/stdc++.h>
using namespace std;

const int N = 20;

double p[N], prob[1 << N], ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n, k;
  cin >> n >> k;

  int invalid = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    invalid += (p[i] == 0.0);
  }
  k = min(k, n - invalid);

  prob[0] = 1.0;
  for (int i = 0; i < (1 << n); ++i) {
    double sum = 0.0;
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) {
        sum += p[j];
      }
    }

    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) {
        prob[i | (1 << j)] += prob[i] * p[j] / sum;
      }
    }

    if (__builtin_popcount(i) == k) {
      for (int j = 0; j < n; ++j) {
        if ((i & (1 << j)) > 0) {
          ans[j] += prob[i];
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}