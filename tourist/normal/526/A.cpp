#include <bits/stdc++.h>

using namespace std;

char s[1234567];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int from = 0; from < n; from++) {
    for (int jump = 1; jump < n; jump++) {
      bool ok = true;
      for (int i = 0; i < 5; i++) {
        int pos = from + i * jump;
        if (pos >= n || s[pos] != '*') {
          ok = false;
          break;
        }
      }
      if (ok) {
        puts("yes");
        return 0;
      }
    }
  }
  puts("no");
  return 0;
}