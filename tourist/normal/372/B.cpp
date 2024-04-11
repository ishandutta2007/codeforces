#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int cnt[44][44][44][44];
int a[44][44], f[44][44];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char ch = getchar();
      while (ch != '0' && ch != '1') ch = getchar();
      a[i][j] = (ch == '1');
    }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if (i == 0 || j == 0) f[i][j] = 0;
      else f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++) {
          int sum = f[xb][yb] - f[xa - 1][yb] - f[xb][ya - 1] + f[xa - 1][ya - 1];
          cnt[xa][ya][xb][yb] = (sum == 0);
        }
  for (int xa = n; xa >= 2; xa--)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++) cnt[xa - 1][ya][xb][yb] += cnt[xa][ya][xb][yb];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = m; ya >= 2; ya--)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++) cnt[xa][ya - 1][xb][yb] += cnt[xa][ya][xb][yb];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++) cnt[xa][ya][xb + 1][yb] += cnt[xa][ya][xb][yb];
  for (int xa = 1; xa <= n; xa++)
    for (int ya = 1; ya <= m; ya++)
      for (int xb = xa; xb <= n; xb++)
        for (int yb = ya; yb <= m; yb++) cnt[xa][ya][xb][yb + 1] += cnt[xa][ya][xb][yb];
  while (q--) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    printf("%d\n", cnt[xa][ya][xb][yb]);
  }
  return 0;
}