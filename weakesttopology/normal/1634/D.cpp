#include <bits/stdc++.h>
int a[100];
int query(int i, int j, int k) {
  std::cout << "? " << i + 1 << ' '<< j + 1 << ' ' << k + 1 << std::endl;
  int res;
  std::cin >> res;
  //int res = std::max({a[i], a[j], a[k]}) - std::min({a[i], a[j], a[k]});
  return res;
}
void answer(int x, int y) {
  std::cout << "! " << x + 1 << ' ' << y + 1 << std::endl;
  //assert(!a[x] || !a[y]);
}
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    std::cin >> N;
    //for (int i = 0; i < N; ++i) {
    //  a[i] = 1 + rng() % 100000;
    //}
    //a[rng() % N] = 0;
    int max = -1, x = -1, y = -1;
    for (int i = 2; i < N; ++i) {
      int d = query(0, 1, i);
      if (d > max) {
        max = d;
        x = i;
      }
    }
    max = -1;
    for (int i = 1; i < N; ++i) {
      if (i == x) continue;
      int d = query(0, i, x);
      if (d > max) {
        max = d;
        y = i;
      }
    }
    int z = 1;
    while (z == x || z == y) ++z;
    int rx = query(0, z, x);
    int ry = query(0, z, y);
    if (rx < max && ry < max) {
      answer(x, y);
    } else if (rx < max) {
      answer(0, y);
    } else {
      answer(0, x);
    }
  }
  exit(0);
}