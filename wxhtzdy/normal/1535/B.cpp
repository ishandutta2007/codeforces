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
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) x.push_back(a[i]);
      else y.push_back(a[i]);
    }
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    vector<int> b;
    for (int i : x) b.push_back(i);
    for (int i : y) b.push_back(i);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (__gcd(b[i], 2 * b[j]) > 1) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}