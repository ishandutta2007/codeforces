#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

bool have[N];
int f[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < N; i++) {
    have[i] = false;
    f[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    have[a] = true;
  }
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (have[i]) {
      f[i]++;
      ans = max(ans, f[i]);
      for (int j = i + i; j < N; j += i) {
        if (f[i] > f[j]) {
          f[j] = f[i];
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}