#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, a[200001], cnt[200001], s[200001], b[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], cnt[a[i]]++;
  std::partial_sum(cnt + 1, cnt + 200001, s + 1);
  int ans = 0, L = -1, R = -1;
  for (int l = 1, r; l <= 200000; l++) {
    if (!cnt[l]) continue;
    r = l;
    while (r < 200000 && cnt[r + 1] >= 2) r++;
    if (r < 200000 && cnt[r + 1]) r++;
    if (s[r] - s[l - 1] > ans) ans = s[r] - s[l - 1], L = l, R = r;
    l = r - (cnt[r] == 1 && r > l);
  }
  std::cout << ans << '\n';
  int p = 0;
  for (int i = L; i <= R; i++)
    for (int j = 1; j < cnt[i]; j++) b[++p] = i;
  for (int i = R; i >= L; i--) b[++p] = i;
  for (int i = 1; i <= ans; i++) std::cout << b[i] << ' ';
  return 0;
}