#include <bits/stdc++.h>

using namespace std;

struct str{
  int val, t;
  bool operator < (const str&other) const {
    return val < other.val;
  }
  str(int _val = 0, int _t = 0) {
    val = _val;
    t = _t;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<str> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].val;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].t;
  }
  str posl;
  posl.val= 1e9 + n + 1;
  posl.t = 0;
  a.push_back(posl);
  sort(a.begin(), a.end());
  multiset<int> s;
  long long ans = 0, sum = 0;
  for (int i = 0, j = 0; i < n + 1; i++) {
    while (!s.empty() && j < a[i].val) {
      auto it = prev(s.end());
      int x = *it;
      s.erase(it);
      j++;
      ans -= x;
      sum += ans;
    }
    ans += a[i].t;
    s.insert(a[i].t);
    j = a[i].val;
  }
  cout << sum << '\n';
  return 0;
}