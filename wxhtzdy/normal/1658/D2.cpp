#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> trie(1, vector<int>(2, -1));
    vector<int> cnt(1, 0);
    for (int i = 0; i < n; i++) {
      int p = 0;
      for (int j = 18; j >= 0; j--) {
        int bit = (a[i] >> j & 1);
        if (trie[p][bit] == -1) {
          trie[p][bit] = trie.size();
          trie.emplace_back(vector<int>(2, -1));
          cnt.push_back(1);
        }
        p = trie[p][bit];
      }
    }
    auto FindMin = [&](int x) {
      int p = 0, ret = 0;
      for (int b = 18; b >= 0; b--) {
        int bit = (x >> b & 1);
        if (trie[p][bit] != -1) {
          p = trie[p][bit];
        } else {
          ret += (1 << b);
          p = trie[p][bit ^ 1];
        }
      }
      return ret;
    };
    auto FindMax = [&](int x) {
      int p = 0, ret = 0;
      for (int b = 18; b >= 0; b--) {
        int bit = (x >> b & 1);
        if (trie[p][bit ^ 1] != -1) {
          ret += (1 << b);
          p = trie[p][bit ^ 1];
        } else {
          p = trie[p][bit];
        }
      }
      return ret;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int mn = FindMin(a[i] ^ l);
      int mx = FindMax(a[i] ^ l);
      if (mn == l && mx == r) {
        ans = a[i];  
      }
    }
    cout << (ans ^ l) << '\n';
  }                                                                    
  return 0;
}