#include <bits/stdc++.h>

using namespace std;

char s[777][777];

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  int ans = 0;
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w - 1; j++) {
      string z = "";
      z += s[i][j];
      z += s[i][j + 1];
      z += s[i + 1][j];
      z += s[i + 1][j + 1];
      sort(z.begin(), z.end());
      if (z == "acef") {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}