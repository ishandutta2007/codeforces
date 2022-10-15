#include <bits/stdc++.h>
using namespace std;

char s[555];
int n;

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 3; i <= n; i++) {
    int x = s[i - 2] - 'A', y = s[i - 1] - 'A', z = s[i] - 'A';
    if ((x + y) % 26 != z) {
      puts("NO"); return 0;
    }
  }
  puts("YES"); return 0;
}