#include <bits/stdc++.h>

using namespace std;

#define SWINS "Stannis"
#define DWINS "Daenerys"

int s_wins(int odd, int even, int k) {
  if (odd + even == k) {
    return (odd % 2 == 1);
  }
  if (k % 2 == 1) {
    if (odd - even >= k) {
      return 1;
    }
    if (even - odd >= k) {
      return 0;
    }
    if (odd % 2 == even % 2) {
      return 1;
    }
    return 0;
  } else {
    if (odd - even >= k) {
      return 0;
    }
    if (even - odd >= k) {
      return 0;
    }
    if (odd % 2 == even % 2) {
      return 0;
    }
    return 1;
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    if (foo % 2 == 1) {
      odd++;
    } else {
      even++;
    }
  }
  puts(s_wins(odd, even, k) ? SWINS : DWINS);
  return 0;
}