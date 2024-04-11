/**
 *    author:  tourist
 *    created: 12.01.2022 18:29:54       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
      if (i > 0) {
        cout << " ";
      }
      cout << i + 1;
    }
    cout << '\n';
    return 0;
  }
  int bits = 0;
  while ((1 << (bits + 1)) <= k) {
    bits += 1;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  vector<int> res;
  int beg = 0;
  while (beg < n) {
    int end = beg;
    while (end + 1 < n && (a[order[end + 1]] >> bits) == (a[order[end]] >> bits)) {
      end += 1;
    }
    // (a[order[beg]] >> bits)..(a[order[end]] >> bits) are all equal
    if (end + 1 < n && (a[order[end + 1]] >> (bits + 1)) == (a[order[end]] >> (bits + 1))) {
      int beg_2 = end + 1;
      int end_2 = beg_2;
      while (end_2 + 1 < n && (a[order[end_2 + 1]] >> bits) == (a[order[end_2]] >> bits)) {
        end_2 += 1;
      }
      vector<vector<int>> trie(1, vector<int>(2, -1));
      vector<int> idx(1, -1);
      for (int i = beg; i <= end; i++) {
        int t = 0;
        for (int j = bits - 1; j >= 0; j--) {
          int bit = (a[order[i]] >> j) & 1;
          if (trie[t][bit] == -1) {
            trie[t][bit] = (int) trie.size();
            trie.emplace_back(2, -1);
            idx.push_back(-1);
          }
          t = trie[t][bit];
        }
        idx[t] = order[i];
      }
      bool found = false;
      for (int i = beg_2; i <= end_2; i++) {
        int t = 0;
        for (int j = bits - 1; j >= 0; j--) {
          int bit = ((a[order[i]] >> j) & 1) ^ 1;
          if (trie[t][bit] == -1) {
            bit ^= 1;
          }
          assert(trie[t][bit] != -1);
          t = trie[t][bit];
        }
        assert(idx[t] != -1);
        int val = a[order[i]] ^ a[idx[t]];
        if (val >= k) {
          res.push_back(order[i]);
          res.push_back(idx[t]);
          found = true;
          break;
        }
      }
      if (!found) {
        res.push_back(order[beg]);
      }
      beg = end_2 + 1;
    } else {
      res.push_back(order[beg]);
      beg = end + 1;
    }
  }
  if (res.size() < 2) {
    cout << -1 << '\n';
    return 0;
  }
  cout << res.size() << '\n';
  for (int i = 0; i < (int) res.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i] + 1;
  }
  cout << '\n';
  return 0;
}