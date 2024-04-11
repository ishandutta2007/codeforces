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
int n, q, ch[8000001][2], cnt[8000001], tot, tag;
bool vis[300001];
void Insert(int x) {
  int now = 0;
  for (int i = 20; i >= 0; i--) {
    int id = (x >> i) & 1;
    if (!ch[now][id]) ch[now][id] = ++tot;
    cnt[now = ch[now][id]]++;
  }
}
int Query() {
  int ans = 0, now = 0;
  for (int i = 20; i >= 0; i--) {
    int id = (tag >> i) & 1;
    if (cnt[ch[now][id]] == (1 << i)) id ^= 1, ans += 1 << i;
    now = ch[now][id];
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (vis[x]) continue;
    Insert(x), vis[x] = true;
  }
  while (q--) {
    int x;
    std::cin >> x, tag ^= x;
    std::cout << Query() << '\n';
  }
  return 0;
}