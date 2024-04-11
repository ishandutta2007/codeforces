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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> already(n + 1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (already[i] >= a[i]) {
        already[i + 1] += (already[i] - a[i] + 1);
      }
      for (int j = i + 2; j <= min(n, i + a[i]); j++) {
        already[j]++;
      }
      if (i + a[i] > n) {
        ans += i + a[i] - n;
      }
    }
    ans += max(already[n], a[n] - 1);
    cout << ans << '\n';
  }
}