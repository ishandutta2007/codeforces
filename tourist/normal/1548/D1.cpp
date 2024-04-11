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
  vector<vector<int>> cnt(2, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    cnt[x[i] / 2 % 2][y[i] / 2 % 2] += 1;
  }
  long long ans = 0;
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
  assert(ans % 6 == 0);
  cout << ans / 6 << '\n';
  return 0;
}