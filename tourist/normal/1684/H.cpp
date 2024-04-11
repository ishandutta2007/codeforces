/**
 *    author:  tourist
 *    created: 19.05.2022 20:11:05       
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
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int len = (int) s.size();
    int bc = 0;
    for (char c : s) {
      bc += (c == '1');
    }
    if (bc == 0) {
      cout << -1 << '\n';
      continue;
    }
    int goal = 1;
    while (goal < bc) {
      goal <<= 1;
    }
    int add = goal - bc;
    vector<int> coeff(len, 0);
    int until = len;
    int ptr = len - 2;
    while (ptr >= 0) {
      if (s[ptr] == '0') {
        ptr -= 1;
        continue;
      }
      int x = ptr;
      while (x > 0 && s[x - 1] == '1') {
        x -= 1;
      }
      int v = 1;
      if (ptr + 2 < len && coeff[ptr + 2] == 0) {
        if (add == 2) {
          for (int j = ptr + 2; j < until; j++) {
            if (coeff[j] == 1 && coeff[j - 1] == 0) {
              coeff[j] = 0;
              add += 1;
              break;
            }
          }
          until = ptr + 2;
        }
        if (add >= 3) {
          v = 3;
        }
      }
      for (int i = ptr; i >= x; i--) {
        if (v == 0) {
          coeff[i] = 0;
          v = 1;
          continue;
        }
        if (v == 1) {
          if (add >= 1) {
            add -= 1;
            coeff[i] = 1;
            v = 3;
          } else {
            coeff[i] = 0;
            v = 1;
          }
          continue;
        }
        if (v == 3) {
          if (add == 2) {
            for (int j = ptr + 2; j < until; j++) {
              if (coeff[j] == 1 && coeff[j - 1] == 0) {
                coeff[j] = 0;
                add += 1;
                break;
              }
            }
            until = ptr + 2;
          }
          if (add >= 3) {
            add -= 3;
            coeff[i] = 3;
            v = 0;
          } else {
            coeff[i] = 0;
            v = 1;
          }
          continue;
        }
        assert(false);
      }
      ptr = x - 1;
    }
    if (add > 0) {
      assert(len >= 5);
      coeff.assign(len, 0);
      coeff[len - 4] = 7;
    }
    vector<pair<int, int>> seq;
    int sum = 0;
    ptr = 0;
    while (ptr < len) {
      int take = (coeff[ptr] == 7 ? 4 : (coeff[ptr] == 3 ? 3 : (coeff[ptr] == 1 ? 2 : 1)));
      assert(ptr + take <= len);
      seq.emplace_back(ptr, ptr + take - 1);
      int num = 0;
      for (int i = ptr; i < ptr + take; i++) {
        num = num * 2 + (int) (s[i] - '0');
      }
      sum += num;
      ptr += take;
    }
    cout << seq.size() << '\n';
    for (auto& p : seq) {
      cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
  }
  return 0;
}