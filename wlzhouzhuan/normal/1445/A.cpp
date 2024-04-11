#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, x, a[N], b[N];
int read() {
  int x; cin >> x; return x; 
}
int main() {
  int T = read();
  while (T--) {
    n = read(), x = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] + b[n + 1 - i] > x) {
        ok = 0; break;
      }
    }
    puts(ok ? "Yes" : "No");
  }
}