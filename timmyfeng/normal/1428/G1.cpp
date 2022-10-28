#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;
const int L = 6 + 1;

priority_queue<array<long long, 2>> buckets[3];
long long max_sum[L][N];
long long fortune[L];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 1; i < L; ++i) {
    cin >> fortune[i];
  }

  for (int i = 0; i < L; ++i) {
    fill(max_sum[i], max_sum[i] + N, -1);
  }
  max_sum[0][0] = 0;

  for (int i = 1, digit = 1; i < L; ++i) {
    for (int j = 0; j < digit; ++j) {
      fill(buckets, buckets + 3, priority_queue<array<long long, 2>>());
      for (int k = 0; j + k * digit < N; ++k) {
        int x = j + k * digit;
        if (max_sum[i - 1][x] != -1) {
          buckets[k % 3].push({max_sum[i - 1][x] - k / 3 * fortune[i], k});
        }

        for (int b = 0; b < 3; ++b) {
          while (!buckets[b].empty() && k - buckets[b].top()[1] >= 9 * (t - 1)) {
            buckets[b].pop();
          }

          if (!buckets[b].empty()) {
            max_sum[i][x] = max(max_sum[i][x], buckets[b].top()[0] + (k - b) / 3 * fortune[i]);
          }
        }

        for (int c = 9 * (t - 1); c <= min(9 * t, k); ++c) {
          int y = x - c * digit;
          int coeff = (c % 3 == 0 ? c / 3 : 3 * (t - 1));
          if (max_sum[i - 1][y] != -1) {
            max_sum[i][x] = max(max_sum[i][x], max_sum[i - 1][y] + coeff * fortune[i]);
          }
        }
      }
    }
    digit *= 10;
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    cout << max_sum[L - 1][x] << "\n";
  }
}