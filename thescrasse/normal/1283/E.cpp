#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, x[200010], a[200010], b[200010], c[200010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i];
  }

  sort(x, x + n);

  a[0] = 1;
  b[0] = 1;
  c[0] = 1;
  for (i = 1; i < n; i++) {
    if (x[i] == x[i - 1]) {
      a[i] = a[i - 1];
      b[i] = b[i - 1];
      c[i] = c[i - 1];
    } else if (x[i] == x[i - 1] + 1) {
      a[i] = min(a[i - 1] + 1, b[i - 1]);
      b[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1]);
      c[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
    } else if (x[i] == x[i - 1] + 2) {
      a[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1]);
      b[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
      c[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
    } else {
      a[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
      b[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
      c[i] = min(min(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
    }
  }
  cout << min(min(a[n - 1], b[n - 1]), c[n - 1]) << ' ';

  for (i = 1; i < n; i++) {
    if (x[i] == x[i - 1]) {
      a[i] = a[i - 1];
      b[i] = max(a[i - 1] + 1, b[i - 1]);
      c[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1]);
    } else if (x[i] == x[i - 1] + 1) {
      a[i] = max(a[i - 1] + 1, b[i - 1]);
      b[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1]);
      c[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
    } else if (x[i] == x[i - 1] + 2) {
      a[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1]);
      b[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
      c[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
    } else {
      a[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
      b[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
      c[i] = max(max(a[i - 1] + 1, b[i - 1] + 1), c[i - 1] + 1);
    }
  }
  cout << max(max(a[n - 1], b[n - 1]), c[n - 1]);

  return 0;
}