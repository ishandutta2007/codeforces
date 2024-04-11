#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
      cin >> y[i];
    }
    sort(x.begin(), x.end());
    vector<int> L(n);
    int ptr = n - 1;
    for (int i =  n - 1; i >= 0; i--) {
      while (ptr >= 0 && x[ptr] >= x[i] - k) {
        --ptr;
      }
      L[i] = i - ptr;
    }
    vector<int> R(n);
    ptr = 0;
    for (int i = 0; i < n; i++) {
      while (ptr < n && x[ptr] <= x[i] + k) {
        ++ptr;
      }
      R[i] = ptr - i;
    }
    for (int i = 1; i < n; i++) {
      L[i] = max(L[i], L[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      R[i] = max(R[i], R[i + 1]);
    }
    int ans = R[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, L[i - 1] + R[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}