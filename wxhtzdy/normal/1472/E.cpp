/**
 *  author: milos
 *  created: 04.01.2021 15:51:18
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
    vector<pair<int, int>> a(n);
    vector<pair<pair<int, int>, int>> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      b[i].first.first = a[i].first;
      b[i].first.second = a[i].second;
      b[i].second = i;
    }
    sort(b.begin(), b.end());
    vector<pair<int, int>> pref(n);
    pref[0].first = b[0].first.second;
    pref[0].second = b[0].second;
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1];
      if (pref[i].first > b[i].first.second) {
        pref[i].first = b[i].first.second;
        pref[i].second = b[i].second;
      }
    }                  
    vector<pair<pair<int, int>, int>> c(n);
    for (int i = 0; i < n; i++) {
      c[i].first.second = a[i].first;
      c[i].first.first = a[i].second;
      c[i].second = i;
    }
    sort(c.begin(), c.end());
    vector<pair<int, int>> pref2(n);
    pref2[0].first = c[0].first.second;
    pref2[0].second = c[0].second;
    for (int i = 1; i < n; i++) {
      pref2[i] = pref2[i - 1];      
      if (pref2[i].first > c[i].first.second) {
        pref2[i].first = c[i].first.second;
        pref2[i].second = c[i].second;
      }
    }
    /*for (int i = 0; i < n; i++) {
      cout << c[i].first.first << " " << c[i].first.second << " " << c[i].second << '\n';
    }
    cout << "prvi " << pref2[0].second << '\n';*/
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      auto it = lower_bound(b.begin(), b.end(), make_pair(make_pair(a[i].first, 0), 0));
      if (it != b.begin()) {
        it = prev(it);
        int d = distance(b.begin(), it);
        bool ok = true;
        if (pref[d].second == i) {
          if (it == b.begin()) {
            ok = false;
          }
          if (ok) it = prev(it);
          if (ok) d = distance(b.begin(), it);
        }
        if (ok && pref[d].first < a[i].second) {
          ans.push_back(pref[d].second + 1);
          continue;
        }                 
      }
      /*cout << "mudja " << i + 1 << '\n';*/
      it = lower_bound(c.begin(), c.end(), make_pair(make_pair(a[i].first, 0), 0));
      if (it != c.begin()) {
        it = prev(it);
        int d = distance(c.begin(), it);
        /*cout << d << '\n';*/
        if (pref2[d].second == i) {
          if (it == c.begin()) {
            ans.push_back(-1);
            continue;
          }
          it = prev(it);
          d = distance(c.begin(), it);
        }
        /*cout << "hello " << i + 1 << " " << d << '\n';*/
        if (pref2[d].first < a[i].second) {
          ans.push_back(pref2[d].second + 1);
          continue;
        }
      }
      ans.push_back(-1);  
    }
    for (int i = 0; i < n; i++) {
      assert((i + 1) != ans[i]);
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}