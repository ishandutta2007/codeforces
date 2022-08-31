/**
 *    author:  tourist
 *    created: 10.11.2018 18:24:55       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> w(n);
  for (int i = 1; i < n; i++) {
    int foo;
    long long bar;
    cin >> foo >> bar;
    foo--;
    w[i] = w[foo] ^ bar;
  }
  sort(w.begin(), w.end());
  vector<int> from(n), to(n);
  for (int i = 0; i < n; i++) {
    from[i] = 0;
    to[i] = n - 1;
  }
  vector<int> R(n), L(n);
  long long ans = 0;
  for (int bit = 61; bit >= 0; bit--) {
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && (w[end] ^ w[end + 1]) < (1LL << bit)) {
        end++;
      }
      R[beg] = end;
      L[end] = beg;
      beg = end + 1;
    }
    long long add = 0;
    for (int i = 0; i < n; i++) {
      if (from[i] > to[i]) {
        continue;
      }
      if (w[i] & (1LL << bit)) {
        if (w[to[i]] & (1LL << bit)) {
          add += to[i] - L[to[i]] + 1;
        }
      } else {
        if (!(w[from[i]] & (1LL << bit))) {
          add += R[from[i]] - from[i] + 1;
        }
      }
    }
    long long take = 0;
    if (add < k) {
      k -= add;
      ans += (1LL << bit);
      take = 1;
    }
    for (int i = 0; i < n; i++) {
      if (from[i] > to[i]) {
        continue;
      }
      if (((w[i] >> bit) & 1) == take) {
        if (w[from[i]] & (1LL << bit)) {
          to[i] = from[i] - 1;
        } else {
          to[i] = R[from[i]];
        }
      } else {
        if (!(w[to[i]] & (1LL << bit))) {
          from[i] = to[i] + 1;
        } else {
          from[i] = L[to[i]];
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}