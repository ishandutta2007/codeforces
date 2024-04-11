#include <bits/stdc++.h>
using namespace std;
#define int int64_t


int32_t main() {
  int L, n; cin >> L >> n;
  vector<int> house(n);
  for (int i = 0; i < n; ++i) cin >> house[i];

  vector<pair<int, int>> range_rec;

  auto try2 = [&](int diff, int len) -> int {
    // cout << "try2 diff len " << diff << ' ' << len << endl;
    range_rec.clear();
    int l = 0, r = 0;
    int mnlen = len;
    int mxlen = len + diff;
    for (int i = 0; i < n; ++i) {
      int at = house[i];
      int nl = l + mnlen;
      int nr = r + mxlen;
      if (nr < at) return -1; // too short
      if (i == n - 1) {
        if (nr < L) return -1;
        if (L < nl) return 1; // too long
      } else {
        if (house[i + 1] < nl) return 1;
        nr = min(nr, house[i + 1]);
      }
      // cout << "i l r at nl nr " << i << ' ' << l << ' ' << r << ' ' << at << ' ' << nl << ' ' << nr << endl;
      nl = max(nl, at);
      l = nl;
      r = nr;
      range_rec.emplace_back(l, r);
    }
    return 0;
  };

  auto try1 = [&](int diff) {
    int l = 1, r = L - diff;
    while (l <= r) {
      int len = (l + r) / 2;
      int res = try2(diff, len);
      // cout << "diff len res " << diff << ' ' << len << ' ' << res << endl;
      if (res == -1) l = len + 1;
      if (res == 1) r = len - 1;
      if (res == 0) return len;
    }
    return (int)-1;
  };

  int dl = 0, dr = L - 1;
  while (dl < dr) {
    int dm = (dl + dr) / 2;
    int base = try1(dm);
    // cout << "dm base " << dm << ' ' << base << endl;
    if (base == -1) dl = dm + 1;
    else dr = dm;
  }

  int base = try1(dl);
  assert(try2(dl, base) == 0);

  int mnl = base, mxl = base + dl;

  vector<int> pts{L};
  int now = L;
  while (now) {
    if ((int)range_rec.size() - (int)pts.size() - 1 < 0) break;
    auto rec = range_rec[(int)range_rec.size() - (int)pts.size() - 1];
    int pl = now - mxl;
    int pr = now - mnl;
    int right = min(pr, rec.second);
    // cout << "now rec() pl pr right " << now << ' ' << rec.first << ' ' << rec.second << ' ' << pl << ' ' << pr << ' ' << right << endl;
    pts.push_back(now = right);
  }
  pts.emplace_back(0);

  // cout << "pts ";
  // for (int i : pts) cout << i << ' ';
  // cout << endl;
  reverse(pts.begin(), pts.end());

  for (int i = 0; i < n; ++i) cout << pts[i] << ' ' << pts[i + 1] << '\n';

  // cout << "dl base " << dl << ' ' << base << endl;

  // for (auto [l, r] : range_rec) {
  //   cout << "l r " << l << ' ' << r << endl;
  // }

  
}