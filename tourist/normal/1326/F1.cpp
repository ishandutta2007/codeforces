/**
 *    author:  tourist
 *    created: 19.03.2020 17:59:04       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

int L[14][64];
int R[14][64];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<string> old_s = s;
  vector<long long> ret(1 << (n - 1));
  int half = n / 2;
  for (int sub = 0; sub < (1 << n); sub++) {
    if (__builtin_popcount(sub) != half) {
      continue;
    }
    vector<int> people;
    for (int i = 0; i < n; i++) {
      if (sub & (1 << i)) {
        people.push_back(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (!(sub & (1 << i))) {
        people.push_back(i);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        s[i][j] = old_s[people[i]][people[j]];
      }
    }
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    {
      vector<int> order(half);
      iota(order.begin(), order.end(), 0);
      do {
        int mask = 0;
        for (int i = 0; i < half - 1; i++) {
          if (s[order[i]][order[i + 1]] == '1') {
            mask |= (1 << i);
          }
        }
        L[order[half - 1]][mask] += 1;
      } while (next_permutation(order.begin(), order.end()));
    }
    {
      vector<int> order(n - half);
      iota(order.begin(), order.end(), half);
      do {
        int mask = 0;
        for (int i = 0; i < n - half - 1; i++) {
          if (s[order[i]][order[i + 1]] == '1') {
            mask |= (1 << i);
          }
        }
        R[order[0]][mask] += 1;
      } while (next_permutation(order.begin(), order.end()));
    }
    for (int whoR = half; whoR < n; whoR++) {
      for (int maskR = 0; maskR < (1 << (n - half - 1)); maskR++) {
        int ft = R[whoR][maskR];
        if (ft == 0) {
          continue;
        }
        for (int who = 0; who < half; who++) {
          int m = (maskR << half) | (s[whoR][who] == '1' ? (1 << (half - 1)) : 0);
          int* LL = L[who];
          for (int mask = 0; mask < (1 << (half - 1)); mask++) {
            ret[m + mask] += ft * LL[mask];
          }
        }
      }
    }
  }
  for (int i = 0; i < (1 << (n - 1)); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ret[i];
  }
  cout << '\n';
  cerr << "time = " << clock() << " ms" << '\n';
  return 0;
}