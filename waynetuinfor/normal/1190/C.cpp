#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  array<int, 2> cnt{};
  for (int i = k; i < n; ++i) cnt[s[i] - '0']++;
  for (int i = k; i <= n; ++i) {
    if (cnt[0] == n - k || cnt[1] == n - k) {
      cout << "tokitsukaze" << "\n";
      return 0;
    }
    if (i < n) {
      cnt[s[i] - '0']--;
      cnt[s[i - k] - '0']++;
    }
  }
  for (int j = 0; j < 2; ++j) {
    vector<set<int>> pos(2);
    for (int i = k; i < n; ++i) pos[s[i] - '0'].insert(i);
    for (int i = 0; i < k; ++i) pos[j].insert(i);

    auto Check = [&](int c) {
      return pos[c].size() < 2 || *pos[c].rbegin() - *pos[c].begin() < k;
    };

    for (int i = k; i <= n; ++i) {
      if (!Check(0) && !Check(1)) {
        cout << "once again" << "\n";
        return 0;
      }
      if (i < n) {
        pos[s[i] - '0'].erase(i);
        pos[j].insert(i);
        pos[j].erase(i - k);
        pos[s[i - k] - '0'].insert(i - k);
      }
    }
  }
  cout << "quailty" << "\n";
  return 0;
}