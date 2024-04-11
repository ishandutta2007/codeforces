#include <bits/stdc++.h>
using namespace std;
long long int t, n, i, j, k, l, arr[200009], brr[200009], crr[200009], a, b, c,
    d, e, f, g, h;
vector<long long int> v;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    long long int flag = 0, tot = 1;
    for (i = 1; i <= n; i++) {
      if (arr[i] == 0) {
        flag++;
        if (flag == 2) {
          tot = 0;
          break;
        }
      } else {
        flag = 0;
      }
    }
    if (tot == 0)
      printf("-1\n");
    else {
      long long int ans = 1;
      flag = 0;
      for (i = 1; i <= n; i++) {
        if (arr[i] == 1) {
          flag++;
          if (flag == 1)
            ans += 1;
          else if (flag == 2) {
            ans += 5;
            flag = 1;
          } else if (flag == 3) {
            ans += 1;
            flag = 1;
          }
        } else {
          flag = 0;
        }
      }
      if (arr[n - 1] == 0 && arr[n] == 0 && arr[n - 2] == 1 && n > 2)
        ans += 1;
      else if (arr[n - 1] == 0 && arr[n] == 0 && arr[n - 2] == 0 && n > 2)
        ans += 2;
      printf("%lld\n", ans);
    }
  }
  return 0;
}