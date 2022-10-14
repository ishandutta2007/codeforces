/**
 *    author:  milos
 *    created: 08.05.2021 16:01:58       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int j = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      continue;
    }   
    bool ok = true;
    int x = a[i];
    while (x > 0) {
      if (x % 10 != 4 && x % 10 != 7) {
        ok = false;
      }
      x /= 10;
    }
    if (ok && (j == -1 || a[j] < a[i])) {
      j = i;
    }
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << '\n';
    return 0;
  }
  if (j == -1) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int l) {
    return a[i] < a[l];  
  });
  vector<int> where(n);
  for (int i = 0; i < n; i++) {
    where[p[i]] = i;
  }
  vector<pair<int, int>> ans;
  int val = j;
  for (int i = 0; i < n; i++) {
    if (p[i] == i) {
      continue;
    }
    if (i != j) {
      ans.emplace_back(i, j);
      swap(p[where[i]], p[where[j]]);
      swap(where[i], where[j]);
      j = i;  
      //p[val] = i;
    }
    if (i != p[i]) {
      assert(i == j);
      ans.emplace_back(j, p[i]);
      int sv = p[i];
      swap(p[where[i]], p[where[sv]]);
      swap(where[j], where[sv]);
      j = sv;
    }
  }
  /*if (j != where[j]) {
   ans.emplace_back();
  }*/      
  cout << (int) ans.size() << '\n';
  assert((int) ans.size() <= 2 * n);
  auto Check = [&]() {
    auto x = a;
    for (int i = 0; i < (int) ans.size(); i++) {
      swap(x[ans[i].first], x[ans[i].second]);
    }
    auto c = a;
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
      if (x[i] != c[i]) {
        return false;
      }
    }
    return true;
  };
  for (auto& x : ans) {
    if (x.first > x.second) {
      swap(x.first, x.second);
    }
    cout << x.first + 1 << " " << x.second + 1 << '\n';
  }
  assert(Check());
  return 0;
}