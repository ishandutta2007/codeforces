/**
 *    author:  milos
 *    created: 22.03.2021 21:13:29       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    ++cnt[a[i]];
  }
  set<pair<int, int>> s;
  for (auto& p : cnt) {
    s.insert(make_pair(-p.second, p.first));
  }
  vector<tuple<int, int, int>> ans;
  while ((int) s.size() >= 3) {
    auto it1 = *s.begin();
    s.erase(s.begin()); 
    auto it2 = *s.begin();
    s.erase(s.begin());
    auto it3 = *s.begin();
    s.erase(s.begin());
    ans.emplace_back(it3.second, it2.second, it1.second);
    if (it1.first < -1) {
      s.insert({it1.first + 1, it1.second});
    }
    if (it2.first < -1) {
      s.insert({it2.first + 1, it2.second});
    }
    if (it3.first < -1) {
      s.insert({it3.first + 1, it3.second});
    }
  }
  cout << ans.size() << '\n';
  for (auto& i : ans) {                                               
    vector<int> b;
    b.push_back(get<0>(i));
    b.push_back(get<1>(i));
    b.push_back(get<2>(i));
    sort(b.begin(), b.end());
    cout << b[2] << " " << b[1] << " " << b[0] << '\n'; 
  }
  return 0;
}