#include <bits/stdc++.h>
using namespace std;

const int N = 30;

long long freq[N];
long long memo[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> freq[i];
  }

  while (q--) {
    int t, x;
    long long y;
    cin >> t >> x >> y;

    if (t == 1) {
      freq[x] = y;
    } else {
      copy(freq, freq + n, memo);

      long long ones = 0;
      for (int i = 0; i <= x; ++i) {
        ones += (1 << i) * freq[i] - freq[i];
        y = max(0LL, y - freq[i]);
      }

      long long ans = y <= ones ? y : LLONG_MAX;
      long long cur = 0;

      int i = 1;
      while (y > 0) {
        while (x + i < n && freq[x + i] == 0) {
          ++i;
        }
        if (x + i == n) {
          break;
        }

        if ((1 << i) <= y) {
          long long use = min(y / (1 << i), freq[x + i]);
          ones += ((1 << (x + i)) - (1 << i)) * use;
          cur += (1 << i) * use - use;
          y -= (1 << i) * use;
          freq[x + i] -= use;
        } else {
          ++cur;
          --freq[x + i];
          if (i == 1) {
            ones += (1 << (x + i)) - (1 << i);
            y = max(0LL, y - 2);
          } else {
            freq[x + i - 1] += 2;
          }
          i = max(1, i - 1);
        }

        if (y <= ones) {
          ans = min(ans, cur + y);
        }
      }

      cout << (ans == LLONG_MAX ? -1 : ans) << "\n";

      copy(memo, memo + n, freq);
    }
  }
}