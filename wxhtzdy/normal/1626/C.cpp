#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
      cin >> k[i];
    }
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++) {
      segs.emplace_back(k[i] - h[i] + 1, k[i]);
    }
    sort(segs.begin(), segs.end());
    int L = 0, R = -1;
    long long ans = 0;
    for (int i = 0; i < segs.size(); i++) {
      int l = segs[i].first;
      int r = segs[i].second;
      if (R < l) {
        long long len = R - L + 1;
        ans += len * (len + 1) / 2;
        L = l;
        R = r;
      } else {
        R = max(R, r);
      }
    }
    long long len = R - L + 1;
    ans += len * (len + 1) / 2;
    cout << ans << '\n';
  }
  return 0;
}