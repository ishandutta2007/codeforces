#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;
const int MAXX = 1000005;

int n, m;
long long ans;

long long tri(int n) {
  return 1LL * n * (n-1) / 2;
}

int main() {
  scanf("%d%d", &n, &m);

  for(int i = 0; i < m; ++i) {
    int x, d;
    scanf("%d%d", &x, &d);

    ans += 1LL * x * n;

    if (d > 0) {
      ans += d * tri(n);
    } else {
      ans += d * (tri(n/2+1) + tri((n+1)/2));
    }
  }

  cout << setprecision(69) << (long double)ans/n << endl;

  return 0;
}