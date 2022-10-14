/**
 *  author: milos
 *  created: 04.01.2021 02:59:21
**/
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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    auto Can = [&](int d) {
      set<pair<int, int>> s;
      for (int i = 0; i < n; i++) {
        s.insert({cnt[a[i]], a[i]});
      }
      vector<int> ans;  
      for (int i = 0; i < n; i++) {
        if (i > d) {
          if (cnt[ans[i - d - 1]] >= 1) {
            s.insert(make_pair(cnt[ans[i - d - 1]], ans[i - d - 1]));
          }  
        }      
        if (s.empty()) {
          return false;
        }
        auto it = *prev(s.end());
        cnt[it.second] -= 1;
        s.erase(prev(s.end())); 
        ans.push_back(it.second);
      }
      return s.empty();  
    };
    int bot = 1, top = n, ans = 0;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (Can(mid)) ans = mid, bot = mid + 1;
      else top = mid - 1;
      for (int i = 0; i < n; i++) {
        cnt[a[i]] = 0;
      }
      for (int i = 0; i < n; i++) {
        cnt[a[i]] += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}