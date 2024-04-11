/**
 *    author:  tourist
 *    created: 06.12.2020 19:19:52       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  while (cin >> n >> a >> b) {
    string s;
    cin >> s;
    set<char> chars_set;
    for (char c : s) {
      chars_set.insert(c);
    }
    vector<char> chars(chars_set.begin(), chars_set.end());
    int cc = (int) chars.size();
    vector<int> L(cc, n + 1);
    vector<int> R(cc, -1);
    vector<int> cnt(cc, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < cc; j++) {
        if (s[i] == chars[j]) {
          L[j] = min(L[j], i);
          R[j] = max(R[j], i);
          cnt[j] += 1;
        }
      }
    }
    vector<int> order(cc);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return L[i] < L[j];
    });
    vector<int> order2 = order;
    sort(order2.begin(), order2.end(), [&](int i, int j) {
      return R[i] < R[j];
    });
    vector<int> order3 = order;
    sort(order3.begin(), order3.end(), [&](int i, int j) {
      return (L[i] + R[i]) / 2 < (L[j] + R[j]) / 2;
    });
    vector<int> order4 = order;
    sort(order4.begin(), order4.end(), [&](int i, int j) {
      return cnt[i] < cnt[j];
    });
    vector<bool> can(1 << cc, false);
    can[0] = true;
    for (int t = 1; t < (1 << cc); t++) {
      int max_R = -1;
      int min_L = -1;
      int total = 0;
      for (int i : order) {
        if (!(t & (1 << i))) {
          continue;
        }
        if (min_L == -1) {
          min_L = L[i];
        }
        total += cnt[i];
        max_R = max(max_R, R[i]);
      }
      int len = max_R - min_L + 1;
      if (total * b >= a * len) {
        can[t] = false;
        for (int i = 0; i < cc; i++) {
          if (t & (1 << i)) {
            if (can[t ^ (1 << i)]) {
              can[t] = true;
              break;
            }
          }
        }
        if (can[t]) {
          continue;
        }
      }
      int nt = 0;
      for (auto& v : {order, order2, order3, order4}) {
        for (int i : v) {
          if (!(t & (1 << i))) {
            continue;
          }
          nt |= (1 << i);
          if (nt != t && can[nt] && can[t ^ nt]) {
            can[t] = true;
            break;
          }
        }
      }
    }
    string ret = "";
    for (int i = 0; i < cc; i++) {
      if (can[(1 << cc) - 1 - (1 << i)]) {
        ret += chars[i];
      }
    }
    cout << ret.size();
    for (char c : ret) {
      cout << " " << c;
    }
    cout << '\n';
  }
  return 0;
}