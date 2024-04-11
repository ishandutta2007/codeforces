#include <bits/stdc++.h>

const int N = 500000;

void solve(int *b, int n) {
  if (!n) return ;
  int l = 31 - __builtin_clz(n), k = (1 << l);
  
  for (int i = k; i < n; i++) b[i] ^= b[i - k]; 
  solve(b + k, n - k);

  for (int j = 1; j < k; j <<= 1) for (int i = 0; i < k; i++)
    if (i & j) b[i ^ j] ^= b[i];
  std::reverse(b, b + k);

  for (int i = k; i < n; i++) b[i - k] ^= b[i];
}

int b[N + 5], n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  solve(b, n), std::reverse(b, b + n);
  for (int i = 0; i < n; i++) printf("%d%c", b[i], i == n ? '\n' : ' ');
}