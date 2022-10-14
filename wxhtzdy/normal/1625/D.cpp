// cool idea by tourist
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k == 0) {
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int bits = 0;
  while ((1 << (bits + 1)) <= k) {
    bits += 1;
  }
  int beg = 0;
  vector<int> ans;
  while (beg < n) {
    int end = beg;
    while (end + 1 < n && (a[order[end + 1]] >> bits) == (a[order[end]] >> bits)) {
      end += 1;
    }
    if (end + 1 < n && (a[order[end]] >> (bits + 1)) == (a[order[end + 1]] >> (bits + 1))) {
      int L = end + 1, R = L;
      while (R + 1 < n && (a[order[R + 1]] >> bits) == (a[order[R]] >> bits)) {
        R += 1;
      }
      vector<vector<int>> nxt(1, vector<int>(2, -1));
      vector<int> id(1, -1);
      for (int i = beg; i <= end; i++) {
        int node = 0;
        for (int j = bits - 1; j >= 0; j--) {
          int bit = (a[order[i]] >> j) & 1;
          if (nxt[node][bit] == -1) {
            nxt[node][bit] = nxt.size();
            nxt.push_back({-1, -1});
            id.push_back(-1);
          }
          node = nxt[node][bit];
        }
        id[node] = order[i];
      }
      bool ok = true;
      for (int i = L; i <= R; i++) {
        int node = 0;
        for (int j = bits - 1; j >= 0; j--) {
          int bit = (a[order[i]] >> j) & 1;
          bit ^= 1;
          if (nxt[node][bit] == -1) {
            bit ^= 1;
          }
          node = nxt[node][bit];
        }
        if ((a[id[node]] ^ a[order[i]]) >= k) {
          ans.push_back(id[node]);
          ans.push_back(order[i]);
          ok = false;
          break;
        }
      }
      if (ok) {
        ans.push_back(order[beg]);
      }
      beg = R + 1;
    } else {
      ans.push_back(order[beg]);
      beg = end + 1;
    }
  }
  if (ans.size() < 2) {
    cout << -1 << '\n';
    return 0;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << '\n';
  return 0;
}