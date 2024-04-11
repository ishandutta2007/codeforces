#include <bits/stdc++.h>

using namespace std;

long long start[9] = {9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};

int main() {
  int tt;
  scanf("%d", &tt);
  char abbr[42];
  while (tt--) {
    scanf("%s", abbr);
    string s = "";
    for (int i = 0; abbr[i]; i++) {
      if ('0' <= abbr[i] && abbr[i] <= '9') {
        s += abbr[i];
      }
    }
    int len = s.length();
    int num = 0;
    for (int i = 0; i < len; i++) {
      num = num * 10 + s[i] - '0';
    }
    int diff = num - start[len - 1];
    if (diff < 0) {
      int p10 = 1;
      for (int i = 0; i < len; i++) {
        p10 = p10 * 10;
      }
      diff += p10;
    }
    int res = 1989;
    int p10 = 1;
    for (int i = 0; i < len - 1; i++) {
      p10 *= 10;
      res += p10;
    }
    res += diff;
    printf("%d\n", res);
  }
  return 0;
}