#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int cnt = 0, pos = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) {
      cnt++;
      pos = i;
    }
  }
  if (cnt > 1) {
    cout << "NO\n";
    exit(0);
  }
  for (int i = pos + 1; i + 1 < n; i++) {
    if (a[i] <= a[i + 1]) {
      cout << "NO\n";
      exit(0);
    }
  }
  for (int i = pos - 1; i > 0; i--) {
    if (a[i] <= a[i - 1]) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n"; 
}