/**
 *    author:  tourist
 *    created: 04.01.2020 15:06:11       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = (long long) n * n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    vector<int> b(foo);
    for (int j = 0; j < foo; j++) {
      cin >> b[j];
    }
    bool ok = true;
    for (int j = 0; j < foo - 1; j++) {
      ok &= b[j] >= b[j + 1];
    }
    if (ok) {
      a.emplace_back(b[0], b.back());
    }
  }
  vector<pair<int, int>> events;
  for (auto& p : a) {
    events.emplace_back(p.first, -1);
    events.emplace_back(p.second, 1);
  }
  sort(events.begin(), events.end());
  int balance = 0;
  for (auto& p : events) {
    if (p.second == -1) {
      ++balance;
    } else {
      ans -= balance;
    }
  }
  cout << ans << '\n';
  return 0;
}