#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, deque<int>> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      pos[a[i]].push_back(i);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (pos[a[i]].empty() || pos[a[i]][0] != i) {
        continue;
      }
      long long b = (long long) a[i] * x;
      if (b <= 1e9 && !pos[b].empty()) {
        ans -= 2;
        pos[b].pop_back();
      }
      pos[a[i]].pop_front();
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}