#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  map<pair<int, int>, int> b;
  function<void(int, int, int)> GoDown = [&](int l, int r, int x) {
    --b[make_pair(l, r)];
    if (l == r) {
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
      GoDown(l, mid, x);
    } else {
      GoDown(mid + 1, r, x);
    }
  };
  while (tt--) {
    int k;
    cin >> k;
    int bot = 0, top = n - 1;
    while (bot < top) {
      int mid = bot + top >> 1;
      pair<int, int> cur = {bot, mid};
      if (b.find(cur) == b.end()) {
        cout << "? " << bot + 1 << " " << mid + 1 << endl;
        cin >> b[cur];
        b[cur] = (mid - bot + 1) - b[cur];
      }
      if (k <= b[cur]) top = mid;
      else k -= b[cur], bot = mid + 1;
    }
    GoDown(0, n - 1, bot);
    cout << "! " << bot + 1 << endl;

  }
  return 0;
}