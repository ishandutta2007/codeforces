#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;
 
int main() {
  ios::sync_with_stdio(!cin.tie(0));
 
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    ll sum = a[0] + a[n - 1];
    for (int i = 1; i < n; i++) {
      sum += abs(a[i] - a[i - 1]);
    }
    if (n == 1) {
      cout << a[0] << '\n';
      continue;
    }
    if (n > 1 && a[0] > a[1]) sum -= (a[0] - a[1]);
    if (n > 1 && a[n - 1] > a[n - 2]) sum -= (a[n - 1] - a[n - 2]);
    for (int i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1])
      sum -= a[i] - max(a[i - 1], a[i + 1]);
    }
    cout << sum << '\n';
  }
}