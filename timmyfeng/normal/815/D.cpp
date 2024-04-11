#include <bits/stdc++.h>
using namespace std;

const int N = 500'000;

array<int, 3> rects[3 * N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, q, r;
  cin >> n >> p >> q >> r;

  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    rects[i * 3] = {r, a, b};
    rects[i * 3 + 1] = {c, a, q};
    rects[i * 3 + 2] = {c, p, b};
  }

  long long cur = (long long) p * q;
  long long ans = 0;
  int ptr = 3 * n - 1;

  sort(rects, rects + 3 * n);
  map<int, int> height;
  height[0] = q + 1;
  height[p + 1] = 0;

  for (int i = r; i > 0; --i) {
    while (ptr >= 0 && rects[ptr][0] == i) {
      auto [z, x, y] = rects[ptr];
      --ptr;

      auto it = height.lower_bound(x);
      if (it->second >= y) {
        continue;
      }

      int delta = y - it->second;
      int nxt = x;

      while (true) {
        auto prv = it;
        --prv;

        cur -= (long long) delta * (nxt - prv->first);
        delta = y - prv->second;
        nxt = prv->first;

        if (prv->second > y) {
          break;
        }
        height.erase(prv);
      }

      height[x] = y;
    }
    ans += cur;
  }

  cout << ans << "\n";
}