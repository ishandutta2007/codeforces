#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

long long x[N], sum[N];
int p[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long m, a, cf, cm;
  cin >> n >> a >> cf >> cm >> m;

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  iota(p, p + n, 0);
  sort(p, p + n, [&](int a, int b) {
    return x[a] < x[b];
  });

  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + x[p[i]];
  }

  long long ans_m = x[p[0]], ans_f = 0;
  for (int i = n; i >= 0; --i) {
    if (i < n) {
      m -= a - x[p[i]];
      if (m < 0) {
        break;
      }
    }

    long long l = x[p[0]], r = a;
    while (l < r) {
      long long mini = (l + r + 1) / 2;
      int index = lower_bound(p, p + i, mini, [&](int a, long long b) {
        return x[a] < b;
      }) - p;

      if (mini * index - sum[index] <= m) {
        l = mini;
      } else {
        r = mini - 1;
      }
    }

    if ((n - i) * cf + l * cm > ans_f * cf + ans_m * cm) {
      ans_f = n - i;
      ans_m = l;
    }
  }

  for (int i = 1; i <= ans_f; ++i) {
    x[p[n - i]] = a;
  }

  cout << ans_f * cf + ans_m * cm << "\n";
  for (int i = 0; i < n; ++i) {
    cout << max(x[i], ans_m) << " ";
  }
  cout << "\n";
}