#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

char a[N], b[N], s[N];
int p[N];

int main() {
  int n;
  scanf("%d", &n);
  n--;
  scanf("%s", a);
  scanf("%s", b);
  for (int i = 0; i < n - i - 1; i++) {
    swap(a[i], a[n - i - 1]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 'N') a[i] = 'S'; else
    if (a[i] == 'E') a[i] = 'W'; else
    if (a[i] == 'S') a[i] = 'N'; else
    if (a[i] == 'W') a[i] = 'E';
  }
  for (int i = 0; i < n; i++) {
    a[n + i] = b[i];
  }
  int len = n + n;
  for (int i = 0; i < len; i++) {
    s[i + 1] = a[i];
  }
  int k = 0;
  p[1] = 0;
  for (int i = 2; i <= len; i++) {
    while (k > 0 && s[i] != s[k + 1]) {
      k = p[k];
    }
    if (s[i] == s[k + 1]) {
      k++;
    }
    p[i] = k;
  }
  int z = p[len];
  while (z > n) {
    z = p[z];
  }
  puts(z > 0 ? "NO" : "YES");
  return 0;
}