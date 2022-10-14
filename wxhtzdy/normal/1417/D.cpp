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
    long long s = accumulate(a.begin(), a.end(), 0LL);
    if (s % n != 0) {
      cout << -1 << '\n';
      continue;
    }       
    s /= n;
    vector<tuple<int, int, int>> ops;
    for (int i = 1; i < n; i++) {
      if (a[i] % (i + 1) == 0) {
        ops.emplace_back(i + 1, 1, a[i] / (i + 1));
      } 
    }
    for (int i = 1; i < n; i++) {
      if (a[i] % (i + 1) != 0) {
        int md = i + 1 - (a[i] % (i + 1));
        ops.emplace_back(1, i + 1, md);
        a[i] += md;
        ops.emplace_back(i + 1, 1, a[i] / (i + 1));
      }
    }
    for (int i = 1; i < n; i++) {
      ops.emplace_back(1, i + 1, s);
    }
    cout << ops.size() << '\n';
    for (int i = 0; i < ops.size(); i++) {
      cout << get<0>(ops[i]) << " " << get<1>(ops[i]) << " " << get<2>(ops[i]) << '\n';
    }
  }
  return 0;
}