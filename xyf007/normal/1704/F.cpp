#include <algorithm>
#include <iostream>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, sg[500001];
char s[500005];
bool vis[101];
void Init() {
  for (int i = 2; i <= 100; i++) {
    for (int j = 0; j <= i - 2; j++) vis[sg[j] ^ sg[i - j - 2]] = true;
    while (vis[sg[i]]) sg[i]++;
    for (int j = 0; j <= i - 2; j++) vis[sg[j] ^ sg[i - j - 2]] = false;
  }
  for (int i = 100; i <= 500000; i++) sg[i] = sg[i - 34];
}
void Solve() {
  std::cin >> n >> (s + 1);
  int r = std::count(s + 1, s + n + 1, 'R'), b = n - r;
  if (r != b) {
    std::cout << (r > b ? "Alice\n" : "Bob\n");
    return;
  }
  int l = 1, SG = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] != s[i - 1])
      l++;
    else
      SG ^= sg[l], l = 1;
  }
  SG ^= sg[l];
  std::cout << (SG ? "Alice\n" : "Bob\n");
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  Init();
  int T;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}