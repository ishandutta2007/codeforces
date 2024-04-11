#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << "1\n2 1\n1\n2 1\n";
      continue;
    }
    if (n == 3) {
      cout << "5\n2 3 1\n2\n1 3\n3 2\n";
      continue;
    }
    vector<int> a(n + 1);
    int mid = n / 2;
    a[mid + 1] = n;
    for (int i = mid + 2; i < n; i++) {
      a[i] = i - 1;
    }
    a[mid] = 1;
    for (int i = 2; i < mid; i++) {
      a[i] = i + 1;
    }
    a[1] = n - 1;
    a[n] = 2;
    vector<pair<int, int>> swaps;
    int sum = 0;
    for (int i = n - 1; i > mid; i--) {
      swaps.pb({i, 1});
      sum += (i - 1) * (i - 1);
    }
    for (int i = 2; i <= mid; i++) {
      swaps.pb({i, n});
      sum += (n - i) * (n - i);
    }
    swaps.pb({1, n});
    sum += (n - 1) * (n - 1);
    cout << sum << '\n';
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    cout << SZ(swaps) << '\n';
    for (auto it : swaps) {
      cout << it.F << ' ' << it.S << '\n';
    }
  }
}