/**
 *    author:  tourist
 *    created: 06.04.2019 12:41:49       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    long long foo, bar;
    cin >> foo >> bar;
    b[i] = bar - foo + 1;
  }
  vector<pair<long long, int>> events;
  for (int i = 0; i < n - 1; i++) {
    events.emplace_back(a[i + 1] - a[i], -1);
  }
  for (int i = 0; i < m; i++) {
    events.emplace_back(b[i], i);
  }
  sort(events.begin(), events.end());
  long long ans = 0;
  long long T = 0;
  long long active = n;
  vector<long long> res(m);
  for (auto& e : events) {
    ans += (e.first - T) * active;
    T = e.first;
    if (e.second == -1) {
      active--;
    } else {
      res[e.second] = ans;
    }
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}