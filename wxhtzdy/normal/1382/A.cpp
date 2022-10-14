#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);         
  int t;
  cin >> t;
  while (t--){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    int x = -1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      if (mp[b[i]] > 0) x = b[i];
    }
    if (x == -1) cout << "NO" << '\n';
    else cout << "YES" << '\n' << 1 << " " << x << '\n';
  }
  return 0;
}