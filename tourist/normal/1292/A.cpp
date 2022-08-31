/**
 *    author:  tourist
 *    created: 19.01.2020 16:32:13       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  vector<int> mask(n, 3);
  int bad = 0;
  while (tt--) {
    int r, c;
    cin >> r >> c;
    --r; --c;
    if (c > 0) {
      bad -= ((mask[c - 1] & mask[c]) == 0);
    }
    if (c < n - 1) {
      bad -= ((mask[c + 1] & mask[c]) == 0);
    }
    mask[c] ^= (1 << r);
    if (c > 0) {
      bad += ((mask[c - 1] & mask[c]) == 0);
    }
    if (c < n - 1) {
      bad += ((mask[c + 1] & mask[c]) == 0);
    }
    cout << (bad == 0 ? "Yes" : "No") << '\n';
  }
  return 0;
}