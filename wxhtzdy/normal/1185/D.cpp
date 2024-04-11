/**
 *    author:  wxhtzdy
 *    created: 18.06.2022 20:44:55
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
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  sort(a.begin(), a.end());
  auto Try = [&](int j) {
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (i != j) {
        b.push_back(a[i]);
      }
    }      
    set<int> d;
    for (int i = 0; i + 1 < (int) b.size(); i++) {
      d.insert(b[i + 1] - b[i]);
    }                 
    return (int) d.size() <= 1;
  };   
  if (Try(0)) {
    cout << order[0] + 1 << '\n';
    return 0;
  }
  if (Try(1)) {
    cout << order[1] + 1 << '\n';
    return 0;
  }
  if (Try(n - 2)) {
    cout << order[n - 2] + 1 << '\n';
    return 0;
  }
  if (Try(n - 1)) {
    cout << order[n - 1] + 1 << '\n';
    return 0;
  }
  if (n == 2) {
    cout << -1 << '\n';
    return 0;
  }
  map<int, int> cnt;
  for (int i = 0; i < n - 1; i++) {
    cnt[a[i + 1] - a[i]] += 1; 
  }
  for (int i = 1; i < n - 1; i++) {
    cnt[a[i] - a[i - 1]] -= 1;
    cnt[a[i + 1] - a[i]] -= 1;
    cnt[a[i + 1] - a[i - 1]] += 1;
    if (cnt[a[i + 1] - a[i - 1]] == n - 2) {
      cout << order[i] + 1 << '\n';
      return 0;
    }
    cnt[a[i + 1] - a[i - 1]] -= 1;
    cnt[a[i + 1] - a[i]] += 1;
    cnt[a[i] - a[i - 1]] += 1;
  }
  cout << -1 << '\n';
  return 0;
}