/**
 *    author:  tourist
 *    created: 10.03.2018 19:02:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  multiset<long long> s;
  long long dec = 0;
  for (int i = 0; i < n; i++) {
    s.insert(dec + v[i]);
    long long cur = 0;
    while (!s.empty() && (*s.begin()) <= dec + t[i]) {
      cur += (*s.begin()) - dec;
      s.erase(s.begin());
    }
    cur += t[i] * (long long) s.size();
    dec += t[i];
    if (i > 0) {
      cout << ' ';
    }
    cout << cur;
  }
  cout << '\n';
  return 0;
}