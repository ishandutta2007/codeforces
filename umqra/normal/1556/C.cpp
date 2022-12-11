#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

const int N = 1010;
long long c[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &c[i]);
  }

  long long cnt = 0;
  for (int l = 0; l < n; l++) {
    long long min_sum = 0;
    long long prefix_sum = 0;
    for (int r = l + 1; r < n; r++) {
      if (l % 2 == 0 && r % 2 == 1) {
        long long lower_b = max(-min_sum, -prefix_sum);
        long long upper_b = min(c[l], c[r] - prefix_sum);
        if (lower_b <= upper_b) {
          eprintf("%d %d - %lld (%lld %lld)\n", l, r, upper_b - lower_b + 1, lower_b, upper_b);
          cnt += upper_b - lower_b + 1;
          if (lower_b == 0 && l + 1 == r) {
            cnt--;
          }
        }
      }

      if (r % 2 == 0) {
        prefix_sum += c[r];
      } else {
        prefix_sum -= c[r];
        min_sum = min(min_sum, prefix_sum);
      }
    }
  }
  printf("%lld\n", cnt);

  return 0;
}