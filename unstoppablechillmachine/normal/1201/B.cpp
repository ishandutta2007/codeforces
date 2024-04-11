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
 
signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int sum = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    mx = max(mx, x);
  }
  if (sum % 2 == 1 || mx * 2 > sum) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
  }
}