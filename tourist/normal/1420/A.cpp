/**
 *    author:  tourist
 *    created: 24.09.2020 20:10:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // to sort a[1], a[2], ..., a[n]:
  // number of exchanges == number of inversions in A == number of pairs (i, j): i < j, a[i] > a[j]
  // max number of inversions in sequence of length n: n * (n - 1) / 2

  //   number of pairs (i, j): i < j
  //   i = 1, j = 2..n: n - 1 pairs
  //   i = 2, j = 3..n: n - 2 pairs
  // ...
  //   i = n-1, j = n: 1 pair
  // in total: (n - 1) + (n - 2) + ... + 1 = (n - 1) * n / 2
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] <= a[i + 1]) {
        sorted = false;
        break;
      }
    }
    // sorted iff a[1] > a[2] > ... > a[n]
    cout << (sorted ? "NO" : "YES") << '\n';
  }
  return 0;
}