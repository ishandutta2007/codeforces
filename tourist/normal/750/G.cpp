#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
const long long one = 1LL;

const int N = 222;

int d[N];
long long f[N][N][N];
long long x[N];

int main() {
  long long real_s;
  cin >> real_s;
  long long ans = 0;
  for (int h1 = 1; h1 <= MAX; h1++) {
    for (int h2 = h1; h2 <= MAX; h2++) {
      for (int lca = 1; lca <= h1; lca++) {
        if (h1 == lca) {
          long long s = real_s;
          x[0] = 1;
          for (int i = 1; i < h2; i++) {
            x[i] = x[i - 1] * 2 + (i <= h2 - lca);
          }
          if (s < x[h2 - 1]) {
            continue;
          }
          s -= x[h2 - 1];
          for (int i = h2 - 2; i >= 0; i--) {
            if (s >= x[i]) {
              s -= x[i];
            }
          }
          if (s == 0) {
            ans++;
          }
          continue;
        }
        // lca < h1 <= h2
        for (int rot = 0; rot < 1 + (h1 != h2); rot++) {
          long long s = real_s;
          if (rot == 0) {
            s -= (one << (h1 - lca)) - 1;
          } else {
            s -= (one << (h2 - lca)) - 1;
          }
          if (s < 0) {
            continue;
          }
          long long first_lca = (one << (h1 - lca + 1)) + (one << (h2 - lca + 1)) - 3;
          long long last_lca = (first_lca << (lca - 1));
          s -= last_lca;
          if (s < 0) {
            continue;
          }
          for (int j = lca - 2; j >= 0; j--) {
            long long cur_lca = (first_lca << j);
            if (s >= cur_lca) {
              s -= cur_lca;
            }
          }
          long long can_get = 0;
          int guys = 0;
          for (int i = 1; i <= h1 - lca - 1; i++) {
            can_get += (one << i) - 1;
            guys++;
          }
          for (int i = 1; i <= h2 - lca - 1; i++) {
            can_get += (one << i) - 1;
            guys++;
          }
          if (s > can_get) {
            continue;
          }
          int kd = 0;
          while (s > 0) {
            d[kd++] = s % 2;
            s /= 2;
          }
          for (int pos = 0; pos <= kd; pos++) {
            for (int carry = 0; carry <= 2 * guys; carry++) {
              for (int cnt = 0; cnt <= guys; cnt++) {
                f[pos][carry][cnt] = 0;
              }
            }
          }
          for (int cnt = 0; cnt <= guys; cnt++) {
            f[0][0][cnt] = 1;
          }
          for (int pos = 0; pos <= kd; pos++) {
            for (int carry = 0; carry <= 2 * guys; carry++) {
              for (int cnt = 0; cnt <= guys; cnt++) {
                long long ft = f[pos][carry][cnt];
                if (ft == 0) {
                  continue;
                }
                if (pos == kd) {
                  if (carry == 0 && cnt == 0) {
                    ans += ft;
                  }
                  continue;
                }
                int new_carry = carry + cnt;
                if ((new_carry & 1) != d[pos]) {
                  continue;
                }
                new_carry >>= 1;
                int ways = (pos < h1 - lca - 1) + (pos < h2 - lca - 1);
                for (int ending = 0; ending <= ways && ending <= cnt; ending++) {
                  f[pos + 1][new_carry][cnt - ending] += ft * ((ways == 2 && ending == 1) ? 2 : 1);
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}