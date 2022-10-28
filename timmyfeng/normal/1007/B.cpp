#include <bits/stdc++.h>
using namespace std;

const int A = 1e5 + 1;

int divisors[A];
int perm[6][3];
int cnt[8];
int a[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < A; ++i) {
    for (int j = i; j < A; j += i) {
      ++divisors[j];
    }
  }

  iota(perm[0], perm[0] + 3, 0);
  for (int i = 1; i < 6; ++i) {
    for (int j = 0; j < 3; ++j) {
      perm[i][j] = perm[i - 1][j];
    }
    next_permutation(perm[i], perm[i] + 3);
  }

  int t;
  cin >> t;
  while (t--) {
    for (int& i : a) {
      cin >> i;
    }

    for (int i = 1; i < (1 << 3); ++i) {
      int g = 0;
      for (int j = 0; j < 3; ++j) {
        if ((i & (1 << j)) > 0) {
          g = __gcd(g, a[j]);
        }
      }
      cnt[i] = divisors[g];
    }

    int ans = 0;
    for (int k = 0; k < 2; ++k) {
      for (int mask = 0; mask < (1 << 6); ++mask) {
        int val = 1;
        int b = 0;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 6; ++j) {
            if ((mask & (1 << j)) > 0) {
              b |= 1 << perm[j][i];
            }
          }
          if (i > 0 || k > 0) {
            val *= cnt[b];
            b = 0;
          }
        }

        ans += (__builtin_popcount(mask) % 2 == 1 ? 1 : -1) * (k == 0 ? 3 : 1) * val;
      }
    }

    ans += 2 * cnt[7];
    ans /= 6;

    cout << ans << "\n";
  }
}