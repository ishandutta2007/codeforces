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
    for (int i = 0; i < n - 1; i++) {
      int x = min(a[i], k);
      a[i] -= x;
      a[n - 1] += x;
      k -= x;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}