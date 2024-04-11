/**
 *    author:  tourist
 *    created: 18.09.2017 16:27:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  if (k > (long long) n * (n - 1) / 2) {
    puts("Impossible");
    return 0;
  }
  k--;
  int cnt = 1;
  while (k >= (long long) cnt * (cnt - 1) / 2) {
    cnt++;
  }
  int extra = (long long) cnt * (cnt - 1) / 2 - k;
  for (int i = 0; i < cnt - extra; i++) {
    putchar('(');
  }
  printf("()");
  for (int i = cnt - extra; i < cnt - 1; i++) {
    putchar('(');
  }
  for (int i = 0; i < cnt - 1; i++) {
    putchar(')');
  }
  for (int i = 0; i < n - cnt; i++) {
    printf("()");
  }
  printf("\n");
  return 0;
}