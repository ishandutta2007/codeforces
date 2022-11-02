#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cross_cnt(int a, int b, int c, int d) {
  int l = max(a, c);
  int r = min(b, d);
//  cout << a << " " << b << " " << c << " " << d << ": " << l << " " << r << endl;
  return max(0, r - l + 1);
}

int main() {
//  freopen("input.txt", "r", stdin);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    if (a[i] == -1) {
      cnt[i] = cross_cnt(i - k, i + k, 0, n - 1);
    } else {
      int cn = cross_cnt(max(0, i - k), min(i + k, n - 1), max(0, a[i] - k), min(a[i] + k, n - 1));
      cnt[i] = cnt[a[i]] + cross_cnt(i - k, i + k, 0, n - 1) - cn;
    }
    printf("%d ", cnt[i]);
  }
  cout << endl;
}