/**
 *    author:  tourist
 *    created: 18.09.2017 16:37:08       
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int N = 777;

char grid[N][N];
int x[N * N], y[N * N], z[N * N];
int was[N][N];
int noise[N][N];

int main() {
  int h, w, q, p;
  scanf("%d %d %d %d", &h, &w, &q, &p);
  for (int i = 0; i < h; i++) {
    scanf("%s", grid[i]);
  }
  int it = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
        int init = (grid[i][j] - 'A' + 1) * q;
        it++;
        int b = 0, e = 1;
        x[0] = i;
        y[0] = j;
        z[0] = init;
        was[i][j] = it;
        while (b < e) {
          noise[x[b]][y[b]] += z[b];
          if (z[b] >= 2) {
            for (int j = 0; j < 4; j++) {
              int xk = x[b] + dx[j];
              int yk = y[b] + dy[j];
              if (xk >= 0 && yk >= 0 && xk < h && yk < w) {
                if (grid[xk][yk] != '*' && was[xk][yk] != it) {
                  x[e] = xk;
                  y[e] = yk;
                  z[e] = z[b] >> 1;
                  was[xk][yk] = it;
                  e++;
                }
              }
            }
          }
          b++;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans += (noise[i][j] > p);
    }
  }
  printf("%d\n", ans);
  return 0;
}