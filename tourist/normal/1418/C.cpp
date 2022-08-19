/**
 *    author:  tourist
 *    created: 14.09.2020 20:21:16       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // him[i] -- the smallest # of skip points required to kill bosses [i; n) if it's our friend's turn to move
    // us[i]  -- ......                                                       if it's our turn to move
    vector<int> him(n + 1);
    vector<int> us(n + 1);
    him[n] = us[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      { // calculate him[i]
        him[i] = us[i + 1] + a[i];
        if (i + 2 <= n) {
          him[i] = min(him[i], us[i + 2] + a[i] + a[i + 1]);
        }
      }
      { // calculate us[i]
        us[i] = him[i + 1];
        if (i + 2 <= n) {
          us[i] = min(us[i], him[i + 2]);
        }
      }
    }
    cout << him[0] << '\n';
  }
  return 0;
}