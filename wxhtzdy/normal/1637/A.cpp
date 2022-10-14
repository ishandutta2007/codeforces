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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto b = a;
    sort(a.begin(), a.end());
    cout << (a == b ? "NO" : "YES") << '\n';
  }                                                                    
  return 0;
}