#include <bits/stdc++.h>

using namespace std;

const int MAX = 20000;

int main() {
  int n;
  scanf("%d", &n);
  int at = 0;
  char foo[42];
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d %s", &d, foo);
    if (foo[0] == 'W' || foo[0] == 'E') {
      if (at == 0 || at == MAX) {
        puts("NO");
        return 0;
      }
    }
    if (foo[0] == 'S') {
      at += d;
      if (at > MAX) {
        puts("NO");
        return 0;
      }
    }
    if (foo[0] == 'N') {
      at -= d;
      if (at < 0) {
        puts("NO");
        return 0;
      }
    }
  }
  puts(at == 0 ? "YES" : "NO");
  return 0;
}