#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, d, m, x, y;

main() {
  cin >> n >> d;
  cin >> m;
  for(int i = 1; i <= m; ++ i) {
    cin >> x >> y;
    if(x + y < d) puts("No");
    else if(x + y > 2 * n - d) puts("No");
    else if(abs(x - y) > d) puts("No");
    else puts("Yes");
  }
}