#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int p, f, cnt_s, cnt_w, s, w;
    cin >> p >> f >> cnt_s >> cnt_w >> s >> w;

    if (s > w) {
      swap(cnt_s, cnt_w);
      swap(s, w);
    }

    int ans = 0;
    for (int i = 0; i <= cnt_s && 1LL * s * i <= p; ++i) {
      int remain_s = cnt_s - i;
      int remain_w = max(0, cnt_w - (p - s * i) / w);
      if (1LL * s * remain_s <= f) {
        remain_w = max(0, remain_w - (f - s * remain_s) / w);
        remain_s = 0;
      } else {
        remain_s -= f / s;
      }
      ans = max(ans, cnt_s + cnt_w - remain_s - remain_w);
    }
    cout << ans << "\n";
  }
}