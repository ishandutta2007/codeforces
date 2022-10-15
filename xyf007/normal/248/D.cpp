#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
int n, k;
char s[500001];
bool Check(int x) {
  int cnt = x, ed = 0, ans = 0, last = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'H') {
      cnt--;
      ed = i;
    } else if (s[i] == 'S') {
      cnt++;
      if (!cnt) {
        ed = i;
      }
    }
  }
  if (cnt < 0) {
    return false;
  }
  cnt = x;
  for (int i = 1; i <= ed; i++) {
    ans++;
    if (s[i] == 'H') {
      if (!cnt--) {
        if (ans + 2 * (ed - i) <= k) {
          return true;
        }
        last = i;
      }
    } else if (s[i] == 'S') {
      if (!++cnt) {
        ans += 2 * (i - last);
        last = -1;
      }
    }
  }
  return ans <= k;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> k >> (s + 1);
  int l = 0, r = n, best = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (Check(mid)) {
      best = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::cout << best;
  return 0;
}