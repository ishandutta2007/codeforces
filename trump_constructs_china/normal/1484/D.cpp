#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
int t, n, a[100001], pre[100001], nxt[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    pre[1] = n;
    std::iota(pre + 2, pre + n + 1, 1);
    std::iota(nxt + 1, nxt + n, 2);
    nxt[n] = 1;
    if (n == 1) {
      if (a[1] == 1) {
        std::cout << "1 1\n";
      } else {
        std::cout << "0\n";
      }
      continue;
    }
    std::set<int> s;
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (std::__gcd(a[i], a[nxt[i]]) == 1) {
        s.emplace(i);
      }
    }
    int now = 1;
    while (!s.empty()) {
      auto it = s.lower_bound(now);
      if (it == s.end()) {
        it = s.begin();
      }
      int d = nxt[*it];
      ans.emplace_back(d);
      if (s.count(d)) {
        s.erase(d);
      }
      if (pre[*it] == d) {
        if (a[*it] == 1) {
          ans.emplace_back(*it);
        }
        break;
      }
      pre[nxt[d]] = pre[d];
      nxt[pre[d]] = nxt[d];
      now = nxt[*it];
      s.erase(it);
      if (std::__gcd(a[pre[now]], a[now]) == 1) {
        s.emplace(pre[now]);
      }
    }
    std::cout << ans.size();
    for (auto &&i : ans) {
      std::cout << ' ' << i;
    }
    std::cout << '\n';
  }
  return 0;
}