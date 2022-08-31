/**
 *    author:  tourist
 *    created: 05.01.2021 17:43:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (int) 1e6 + 10;
  vector<int> h(MAX, 1);
  for (int i = 1; i < MAX; i++) {
    int tmp = i;
    for (int j = 2; j * j <= tmp; j++) {
      if (tmp % j == 0) {
        int cnt = 0;
        while (tmp % j == 0) {
          cnt += 1;
          tmp /= j;
        }
        if (cnt % 2 == 1) {
          h[i] *= j;
        }
      }
    }
    if (tmp > 1) {
      h[i] *= tmp;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = h[a[i]];
    }
    sort(a.begin(), a.end());
    vector<int> b = a;
    int ans0 = 0;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && a[end + 1] == a[end]) {
        end += 1;
      }
      ans0 = max(ans0, end - beg + 1);
      if ((end - beg + 1) % 2 == 0) {
        for (int i = beg; i <= end; i++) {
          b[i] = 1;
        }
      }
      beg = end + 1;
    }
    sort(b.begin(), b.end());
    int ans1 = 0;
    beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && b[end + 1] == b[end]) {
        end += 1;
      }
      ans1 = max(ans1, end - beg + 1);
      beg = end + 1;
    }
    int q;
    cin >> q;
    while (q--) {
      long long w;
      cin >> w;
      cout << (w == 0 ? ans0 : ans1) << '\n';
    }
  }
  return 0;
}