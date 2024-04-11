#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[42];
  char s[42][42];
  for (int id = 0; id < 2; id++) {
    for (int i = 0; i < 2; i++) {
      scanf("%s", s[i]);
    }
    int diff = 0;
    if (s[0][0] == 'X') {
      diff = s[1][1] - s[0][1];
    } else {
      if (s[0][1] == 'X') {
        diff = s[1][1] - s[0][0];
      } else {
        diff = s[0][1] - s[0][0];
      }
    }
    diff = (diff + 3) % 3;
    a[id] = diff;
  }
  puts(a[0] == a[1] ? "YES" : "NO");
  return 0;
}