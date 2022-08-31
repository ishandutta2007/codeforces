/**
 *    author:  tourist
 *    created: 01.08.2021 17:51:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  long long ans = 0;
  for (int rx = 0; rx < 2; rx++) {
    for (int ry = 0; ry < 2; ry++) {
      vector<vector<int>> cnt(2, vector<int>(2));
      for (int i = 0; i < n; i++) {
        if (x[i] % 2 == rx && y[i] % 2 == ry) {
          cnt[x[i] / 2 % 2][y[i] / 2 % 2] += 1;
        }
      }
      for (int xa = 0; xa < 2; xa++) {
        for (int ya = 0; ya < 2; ya++) {
          if (cnt[xa][ya] > 0) {
            long long ways = cnt[xa][ya];
            --cnt[xa][ya];
            for (int xb = 0; xb < 2; xb++) {
              for (int yb = 0; yb < 2; yb++) {
                if (cnt[xb][yb] > 0) {
                  long long ways2 = ways * cnt[xb][yb];
                  --cnt[xb][yb];
                  for (int xc = 0; xc < 2; xc++) {
                    for (int yc = 0; yc < 2; yc++) {
                      if (cnt[xc][yc] > 0) {
                        long long ways3 = ways2 * cnt[xc][yc];
                        int sum = 0;
                        if (xa != xb || ya != yb) sum += 1;
                        if (xa != xc || ya != yc) sum += 1;
                        if (xc != xb || yc != yb) sum += 1;
                        if (sum % 2 == 0) {
                          ans += ways3;
                        }
                      }
                    }
                  }
                  ++cnt[xb][yb];
                }
              }
            }
            ++cnt[xa][ya];
          }
        }
      }
    }
  }
  assert(ans % 6 == 0);
  ans /= 3;
  for (int i = 0; i < n; i++) {
    vector<vector<vector<int>>> cnt(4, vector<vector<int>>(4, vector<int>(4)));
    for (int j = 0; j < n; j++) {
      if (x[i] % 2 == x[j] % 2 && y[i] % 2 == y[j] % 2) {
        continue;
      }
      int g = __gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
      cnt[g % 4][x[j] % 4][y[j] % 4] += 1;
    }
    for (int ga = 0; ga < 4; ga++) {
      for (int xa = 0; xa < 4; xa++) {
        for (int ya = 0; ya < 4; ya++) {
          if (cnt[ga][xa][ya] > 0) {
            long long ways = cnt[ga][xa][ya];
            --cnt[ga][xa][ya];
            for (int gb = 0; gb < 4; gb++) {
              for (int xb = 0; xb < 4; xb++) {
                for (int yb = 0; yb < 4; yb++) {
                  if (cnt[gb][xb][yb] > 0) {
                    if (xa % 2 != xb % 2 || ya % 2 != yb % 2) {
                      continue;
                    }
                    long long ways2 = ways * cnt[gb][xb][yb];
                    int area = ((x[i] % 4) - xa) * ((y[i] % 4) + ya) + (xa - xb) * (ya + yb) + (xb - (x[i] % 4)) * (yb + (y[i] % 4));
                    if (area % 2 != 0) {
                      continue;
                    }
                    area /= 2;
                    int boundary = ga + gb;
                    if (xa != xb || ya != yb) {
                      boundary += 2;
                    }
                    assert(boundary % 2 == 0);
                    int inter = area + 1 - boundary / 2;
                    if (inter % 2 != 0) {
                      ans += ways2;
                    }
                  }
                }
              }
            }
            ++cnt[ga][xa][ya];
          }
        }
      }
    }
  }
  assert(ans % 2 == 0);
  ans /= 2;
  cout << ans << '\n';
  return 0;
}