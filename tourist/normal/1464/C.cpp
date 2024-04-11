/**
 *    author:  tourist
 *    created: 20.12.2020 18:25:51       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long t;
  cin >> n >> t;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = 1 << ((int) (s[i] - 'a'));
  }
  long long actual = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 2) {
      actual -= a[i];
    } else {
      actual += a[i];
    }
  }
  long long goal = actual - t;
  if (goal < 0) {
    cout << "No" << '\n';
    return 0;
  }
  n -= 2;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = 2 * a[i];
  }
  vector<int> cnt(60);
  for (int i = 0; i < n; i++) {
    cnt[__builtin_ctzll(b[i])] += 1;
  }
/*  for (int i = 0; i < 60; i++) {
    long long go = (cnt[i] - 1) / 2 * 2;
    cnt[i + 1] += go / 2;
    cnt[i] -= go;
  }*/
  long long need = 0;
  for (int i = 59; i >= 0; i--) {
    if (goal & (1LL << i)) {
      need += 1;
    }
    need = max(need - cnt[i], 0LL);
    need *= 2;
  }
  cout << (need == 0 ? "Yes" : "No") << '\n';
  return 0;
}