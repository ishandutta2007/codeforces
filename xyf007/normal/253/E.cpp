#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
struct Task {
  int t, s, p, id;
  bool operator<(const Task &b) const { return p > b.p; }
} a[50001];
int n, p;
long long T, ed[50001];
int Check(int x) {
  std::set<Task> s;
  long long now = 0LL;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[i].t - now >= s.begin()->s) {
      ed[s.begin()->id] = now += s.begin()->s;
      s.erase(s.begin());
    }
    if (s.empty()) {
      s.emplace(a[i]);
      now = a[i].t;
      continue;
    }
    if (a[i].p <= s.begin()->p) {
      s.emplace(a[i]);
      continue;
    }
    Task pre = *s.begin();
    s.erase(s.begin());
    pre.s -= a[i].t - now;
    now = a[i].t;
    s.emplace(pre);
    s.emplace(a[i]);
  }
  while (!s.empty()) {
    ed[s.begin()->id] = now += s.begin()->s;
    s.erase(s.begin());
  }
  return ed[a[p].id] == T ? 0 : ed[a[p].id] < T ? -1 : 1;
}
int main(int argc, char const *argv[]) {
#if defined(ONLINE_JUDGE)
  std::freopen("input.txt", "r", stdin);
  std::freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].t >> a[i].s >> a[i].p;
    a[i].id = i;
  }
  std::cin >> T;
  std::sort(a + 1, a + n + 1,
            [](const Task &x, const Task &y) -> bool { return x.t < y.t; });
  for (int i = 1; i <= n; i++) {
    if (a[i].p == -1) {
      p = i;
      break;
    }
  }
  int l = 1, r = 1000000000;
  while (l <= r) {
    int mid = (l + r) >> 1, tmp = Check(a[p].p = mid);
    if (!tmp) {
      std::cout << mid << '\n';
      for (int i = 1; i <= n; i++) {
        std::cout << ed[i] << ' ';
      }
      return 0;
    } else if (tmp < 0) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return 0;
}