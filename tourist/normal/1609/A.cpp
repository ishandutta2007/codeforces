/**
 *    author:  tourist
 *    created: 28.11.2021 17:34:54       
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
    vector<long long> a(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        k += 1;
      }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
      a.back() *= 2;
    }
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
  }
  return 0;
}