/**
 *    author:  tourist
 *    created: 09.08.2021 17:37:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    int z = n;
    for (int i = 0; i < n - 1; i++) {
      if (order[i + 1] == order[i] + 1) {
        z -= 1;
      }
    }
    cout << (z <= k ? "YES" : "NO") << '\n';
  }
  return 0;
}