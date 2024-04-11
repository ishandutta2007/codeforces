#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int64_t> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int64_t> ans(n);
  vector<int64_t> od;
  int64_t mt = 1;
  while (!b.empty()) {
    int cur = 0;
    vector<int64_t> pd;
    for (int i = 0; i < b.size(); ++i) {
      if (b[i] % 2 == 0) {
        pd.push_back(b[i] * mt);
      }
    }
    if (pd.size() + od.size() < ans.size()) {
      ans = od;
      ans.insert(ans.end(), pd.begin(), pd.end());
    }
    vector<int64_t> nxt;
    for (int i = 0; i < b.size(); ++i) {
      if (b[i] % 2 == 0) {
        nxt.push_back(b[i] / 2);
      } else {
        od.push_back(b[i] * mt);
      }
    }
    b = nxt;
    mt <<= 1;
  }
  cout << ans.size() << "\n";
  for (int64_t u : ans) cout << u << ' ';
  cout << "\n";
}