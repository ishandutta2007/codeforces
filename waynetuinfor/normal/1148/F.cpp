#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int64_t> mask(n);
  for (int i = 0; i < n; ++i) cin >> v[i] >> mask[i];
  if (accumulate(v.begin(), v.end(), 0LL) < 0) {
    for (int i = 0; i < n; ++i) v[i] = -v[i];
  }
  vector<vector<int>> pos(62);
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < 62; ++b) {
      if (mask[i] < (1LL << (b + 1))) {
        pos[b].push_back(i);
        break;
      }
    }
  }
  int64_t s = 0;
  int64_t sum = accumulate(v.begin(), v.end(), 0LL);
  for (int b = 0; b < 62; ++b) {
    int64_t vals = 0;
    for (int u : pos[b]) vals += v[u];
    if (vals > 0) {
      s ^= (1LL << b);
      for (int i = 0; i < n; ++i) {
        if (mask[i] >> b & 1) v[i] = -v[i];
      }
    }
  }
  cerr << accumulate(v.begin(), v.end(), 0LL) << "\n";
  cout << s << "\n";
  return 0;
}