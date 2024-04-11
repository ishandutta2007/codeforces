#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }              
    long long s = accumulate(a.begin(), a.end(), 0LL) + n;
    s += *max_element(a.begin(), a.end());
    s -= *min_element(a.begin(), a.end());
    cout << (s <= m ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}