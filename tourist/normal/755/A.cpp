#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n <= 2 ? n + 2 : n - 2);
  return 0;
}