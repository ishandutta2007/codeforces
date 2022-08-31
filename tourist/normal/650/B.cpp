#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int v[N];
int sum[N];
char foo[N];

int main() {
  int n, A, B, T;
  scanf("%d %d %d %d", &n, &A, &B, &T);
  scanf("%s", foo);
  for (int i = 0; i < n; i++) {
    v[i] = 1 + (foo[i] == 'w' ? B : 0);
  }
  if (v[0] > T) {
    printf("%d\n", 0);
    return 0;
  }
  int ans = 0;
  for (int rot = 0; rot < 2; rot++) {
    sum[0] = 0;
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + v[i] + A;
    }
    v[n] = v[0];
    int spent = 0;
    int cur = 0;
    for (int i = n; i >= 1; i--) {
      spent += v[i];
      cur++;
      if (spent > T) {
        break;
      }
      ans = max(ans, cur);
      {
        int back = (n - i) * A;
        int have = T - (spent + back);
        if (have >= 0) {
          int low = 0, high = i - 1;
          while (low < high) {
            int mid = (low + high + 1) >> 1;
            if (sum[mid] <= have) {
              low = mid;
            } else {
              high = mid - 1;
            }
          }
          ans = max(ans, cur + low);
        }
      }
      spent += A;
    }
    for (int i = 1; i < n - i; i++) {
      swap(v[i], v[n - i]);
    }
  }
  ans = min(ans, n);
  printf("%d\n", ans);
  return 0;
}