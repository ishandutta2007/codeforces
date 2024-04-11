#include <bits/stdc++.h>

using namespace std;

const long long MAGIC = 1000;

int main() {
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  if (wb > wr) {
    swap(hr, hb);
    swap(wr, wb);
  }
  if (wr > MAGIC) {
    long long ans = 0;
    for (long long r = 0; r * wr <= c; r++) {
      long long b = (c - r * wr) / wb;
      long long cur = r * hr + b * hb;
      if (cur > ans) {
        ans = cur;
      }
    }
    cout << ans << endl;
    return 0;
  }
  // wb <= wr <= MAGIC
  long long ans = 0;
  long long big = max(wb * hr, wr * hb);
  for (long long r = 0; r < wb; r++) {
    for (long long b = 0; b < wr; b++) {
      long long weight = r * wr + b * wb;
      if (weight > c) {
        continue;
      }
      long long other = (c - weight) / (wr * wb);
      long long cur = r * hr + b * hb + other * big;
      if (cur > ans) {
        ans = cur;
      }
    }
  }
  cout << ans << endl;
  return 0;
}