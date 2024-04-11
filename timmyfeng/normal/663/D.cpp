#include <bits/stdc++.h>
using namespace std;

#define REP(i, l, r) for (int i = l; i <= r; ++i)

const int N = 5000 + 1;
const int K = 90 + 1;

int place[2][K][K][K], when[N][3], type[3], weak[3], freq[3], hacks[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  REP(i, 0, n - 1) {
    REP(j, 0, 2) {
      cin >> when[i][j];
      weak[j] += (when[i][j] < 0);
      freq[j] += (when[i][j] != 0);
    }
  }

  if (weak[0] + weak[1] + weak[2] >= K) {
    cout << 1 << "\n";
    exit(0);
  }

  int m = 0;
  REP(i, 1, n - 1) {
    if (*min_element(when[i], when[i] + 3) < 0) {
      if (i > ++m) {
        swap_ranges(when[i], when[i] + 3, when[m]);
      }
    }
  }

  int ans = INT_MAX;
  REP(a, 1, 6) {
    REP(b, 1, 6) {
      REP(c, 1, 6) {
        type[0] = a, type[1] = b, type[2] = c;

        bool possible = true;
        REP(d, 0, 2) {
          int low = (type[d] == 6) ? 0 : (n >> type[d]) + 1;
          if (low == (n >> (type[d] - 1)) + 1) {
            possible = false;
          } else {
            hacks[d] = freq[d] - low;
            if (hacks[d] < 0) {
              possible = false;
            } else if (hacks[d] > weak[d]) {
              if (freq[d] - weak[d] <= (n >> (type[d] - 1))) {
                hacks[d] = weak[d];
              } else {
                possible = false;
              }
            }
          }
        }

        if (!possible) {
          continue;
        }

        REP(d, 0, hacks[0]) {
          REP(e, 0, hacks[1]) {
            REP(f, 0, hacks[2]) {
              place[0][d][e][f] = INT_MAX;
            }
          }
        }
        place[0][0][0][0] = 1;

        int me = 100 * accumulate(hacks, hacks + 3, 0);
        REP(d, 0, 2) {
          if (when[0][d] > 0) {
            me += 2 * type[d] * (250 - when[0][d]);
          }
        }

        REP(d, 1, m) {
          REP(e, 0, hacks[0]) {
            REP(f, 0, hacks[1]) {
              REP(g, 0, hacks[2]) {
                place[d % 2][e][f][g] = INT_MAX;
              }
            }
          }

          REP(e, 0, hacks[0]) {
            REP(f, 0, hacks[1]) {
              REP(g, 0, hacks[2]) {
                if (place[1 - d % 2][e][f][g] == INT_MAX) {
                  continue;
                }

                REP(h, 0, (1 << 3) - 1) {
                  bool ok = true;
                  int him = 0;

                  REP(i, 0, 2) {
                    if ((h & (1 << i)) == 0) {
                      if (when[d][i] != 0) {
                        him += 2 * type[i] * (250 - abs(when[d][i]));
                      }
                    } else if (when[d][i] >= 0) {
                      ok = false;
                    }
                  }

                  if (ok) {
                    int &p = place[d % 2][e + ((h & 1) > 0)][f + ((h & 2) > 0)][g + ((h & 4) > 0)];
                    p = min(p, place[1 - d % 2][e][f][g] + (him > me));
                  }
                }
              }
            }
          }
        }

        int res = place[m % 2][hacks[0]][hacks[1]][hacks[2]];
        REP(d, m + 1, n) {
          int him = 0;
          REP(e, 0, 2) {
            if (when[d][e] > 0) {
              him += 2 * type[e] * (250 - when[d][e]);
            }
          }
          res += (him > me);
        }

        ans = min(ans, res);
      }
    }
  }

  cout << ans << "\n";
}