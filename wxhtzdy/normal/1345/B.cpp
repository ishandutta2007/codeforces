#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<long long> v;
  v.push_back(2);
  long long nxt = 5;                
  for (int i = 0; i < 100000; i++) {
    v.push_back(v[(int) v.size() - 1] + nxt);
    nxt += 3;
  }
  reverse(v.begin(), v.end());
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int ans = 0;
    while (n > 1) {
      for (auto c : v) {
        if (c <= n) {
          n -= c;
          ans++;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}