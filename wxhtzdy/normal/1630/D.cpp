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
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int g = 0;
    for (int i = 0; i < m; i++) {
      g = __gcd(g, b[i]);
    }
    vector<long long> dp(2);
    for (int i = 1; i <= g; i++) {
      vector<int> v;
      for (int j = i - 1; j < n; j += g) {
        v.push_back(a[j]);
      }
      sort(v.begin(), v.end());
      vector<long long> c(2, -1e16);
      long long s = accumulate(v.begin(), v.end(), 0LL);
      c[0] = s;
      for (int j = 0; j < (int) v.size(); j++) {
        s -= v[j] * 2;
        int id = (j % 2) ^ 1;
        c[id] = max(c[id], s);
      }
      dp[0] += c[0];
      dp[1] += c[1];
    }
    cout << max(dp[0], dp[1]) << '\n';
  }                                                                    
  return 0;
}