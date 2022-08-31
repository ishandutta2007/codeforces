#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

long long t[N], d[N], res[N], q[N];

int main() {
  int n, b;
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> d[i];
    res[i] = -1;
  }
  t[n] = (long long) 1e18;
  int from = 0, to = 0;
  long long ct = 0;
  for (int i = 0; i <= n; i++) {
    while (from < to && ct <= t[i]) {
      ct += d[q[from]];
      res[q[from]] = ct;
      from++;
    }
    ct = max(ct, t[i]);
    if (to - from < b) {
      q[to++] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << res[i];
  }
  cout << endl;
  return 0;
}