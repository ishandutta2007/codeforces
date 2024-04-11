#include <bits/stdc++.h>
using namespace std;

const int N = 500'000 + 2;

long long sum[N];
long long degree[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int parity = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> degree[i];
    parity ^= degree[i] % 2;
  }

  degree[0] = n;
  sort(degree + 1, degree + n + 1);
  reverse(degree + 1, degree + n + 1);

  for (int i = 1; i <= n; ++i) {
    sum[i] = degree[i] + sum[i - 1];
  }

  long long min_a = 0;
  long long max_a = n;
  long long index = n;

  for (long long k = 0; k <= n + 1; ++k) {
    while (index > 0 && degree[index] < k) {
      --index;
    }

    bool ok_l = false;
    bool ok_r = false;

    // new degree on left hand side
    if (k >= 1) {
      long long left = sum[k - 1];
      long long right = k * (k - 1);
      long long index_k = max(index, k - 1);
      right += sum[n] - sum[index_k] + (index_k - (k - 1)) * k;
      if (right - left >= degree[k]) {
        max_a = min(max_a, right - left);
        ok_l = true;
      }
    }

    // new degree on right hand side
    if (k <= n) {
      long long left = sum[k];
      long long right = k * (k - 1);
      long long index_k = max(index, k);
      right += sum[n] - sum[index_k] + (index_k - k) * k;
      if (left - right <= min(k, degree[k])) {
        min_a = max(min_a, left - right);
        ok_r = true;
      }
    }

    if (!ok_l && !ok_r) {
      min_a = n + 1;
    } else if (!ok_l) {
      max_a = min(max_a, degree[k]);
    } else if (!ok_r) {
      min_a = max(min_a, degree[k]);
    }
  }

  min_a += (parity != min_a % 2);
  if (min_a > max_a) {
    cout << -1 << "\n";
  } else {
    for (int i = min_a; i <= max_a; i += 2) {
      cout << i << " ";
    }
    cout << "\n";
  }
}