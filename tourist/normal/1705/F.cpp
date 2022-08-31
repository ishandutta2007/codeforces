/**
 *    author:  tourist
 *    created: 15.07.2022 17:52:18       
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
  int n;
  cin >> n;
  #ifdef LOCAL
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    string real;
    real += string(n / 2, 'T');
    real += string(n - n / 2, 'F');
    shuffle(real.begin(), real.end(), rng);
  #endif
  int Q = 0;
  auto Ask = [&](string s) {
    Q += 1;
    #ifdef LOCAL
      int ret = 0;
      for (int i = 0; i < n; i++) {
        ret += (s[i] == real[i]);
      }
      if (ret == n) {
        debug(Q);
        exit(0);
      }
      return ret;
    #else
      cout << s << endl;
      int ret;
      cin >> ret;
      if (ret == n) {
        debug(Q);
        exit(0);
      }
      return ret;
    #endif
  };
  vector<string> mat = {
    "10000011000111100",
    "01000010101011010",
    "00100010011100110",
    "00010001101100110",
    "00001001011011010",
    "00000100110111100",
    "00000010001110000",
    "00000001001001100",
    "00000000100101010",
    "00000000010010110",
    "11111111111111111"};
  int h = (int) mat.size();
  int w = (int) mat[0].size();
  debug(h, w);
  map<vector<int>, int> mp;
  for (int t = 0; t < (1 << w); t++) {
    vector<int> ans(h);
    for (int i = 0; i < h; i++) {
      int k = 0;
      for (int j = 0; j < w; j++) {
        int b1 = (t >> j) & 1;
        int b2 = (mat[i][j] == '1');
        k += (b1 * b2);
      }
      ans[i] = k;
    }
    if (mp.find(ans) != mp.end()) {
      debug(ans, mp[ans], t);
    }
    assert(mp.find(ans) == mp.end());
    mp[ans] = t;
  }
  debug(mp.size());
  string base(n, 'T');
  string res = base;
  int init = Ask(base);
  int shift = 0;
  while (shift + w <= n) {
    vector<int> ans(h);
    for (int i = 0; i < h; i++) {
      string query = base;
      int cnt = 0;
      for (int j = 0; j < w; j++) {
        if (mat[i][j] == '1') {
          query[shift + j] ^= 'T' ^ 'F';
          cnt += 1;
        }
      }
      int ones = (Ask(query) - init + cnt) / 2;
      ans[i] = ones;
    }
    auto it = mp.find(ans);
    assert(it != mp.end());
    int mask = it->second;
    for (int j = 0; j < w; j++) {
      if ((mask >> j) & 1) {
        res[shift + j] ^= 'T' ^ 'F';
      }
    }
    shift += w;
  }
  while (shift < n) {
    string query = base;
    query[shift] ^= 'T' ^ 'F';
    int got = Ask(query);
    if (got == init + 1) {
      res[shift] = query[shift];
    }
    shift += 1;
  }
  Ask(res);
  assert(false);
  return 0;
}