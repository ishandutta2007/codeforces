#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    long long s = accumulate(c.begin(), c.end(), 0LL);
    int one = s / n;
    vector<int> a(n);
    vector<int> b(n);
    int delta = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (one > 0) {
        delta -= 1;
        b[i - one + 1] += 1;
      }
      c[i] += delta;
      if (c[i] > 0 || one == i + 1) {
        one -= 1;
        a[i] = 1;
      }
      delta += b[i];
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << a[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}