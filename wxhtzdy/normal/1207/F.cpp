#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 5e5 + 5;
const int BLOCK = sqrt(N);

int a[N];
ll sum[BLOCK + 5][BLOCK + 5];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int q;
  cin >> q;
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      for (int i = 1; i <= BLOCK; i++) {
        sum[i][x % i] -= a[x];
      }
      a[x] += y;
      for (int i = 1; i <= BLOCK; i++) {
        sum[i][x % i] += a[x];
      }
    } else {
      if (x <= BLOCK) {
        cout << sum[x][y] << '\n';
      } else {
        ll res = 0;
        for (int i = y; i <= 5e5; i += x) {
          res += a[i];
        }
        cout << res << '\n';
      }
    }
  }
}