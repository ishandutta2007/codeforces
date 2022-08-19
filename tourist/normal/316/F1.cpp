#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int a[1620][1620];
int x[1620*1620], y[1620*1620];
bool was[1620][1620];
int cc[1620][1620];
bool end[1620][1620];
int s[1620*1620];
int px[1620][1620], py[1620][1620];
int lx[1620], ly[1620];

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i=0;i<h;i++)
    for (int j=0;j<w;j++) scanf("%d", &a[i][j]);
  for (int i=0;i<h;i++)
    for (int j=0;j<w;j++) end[i][j] = 0;
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      if (a[i][j] == 1) {
        int cnt = 0;
        for (int x=i-5;x<=i+5;x++)
          for (int y=j-5;y<=j+5;y++)
            if (x >= 0 && y >= 0 && x < h && y < w && a[x][y]) cnt++;
        cc[i][j] = cnt;
      }
//      printf("%03d ", cc[i][j]);
      }
//      printf("\n");
      }
  for (int i=0;i<=255;i++) lx[i] = ly[i] = -1;
  for (int i=0;i<h;i++)
    for (int j=0;j<w;j++)
      if (a[i][j]) {
        was[i][j] = false;
        px[i][j] = lx[cc[i][j]];
        py[i][j] = ly[cc[i][j]];
        lx[cc[i][j]] = i;
        ly[cc[i][j]] = j;
      }
  for (int val=1;val<35;val++) {
    int xx = lx[val], yy = ly[val];
    while (xx >= 0 || yy >= 0) {
      if (!was[xx][yy]) {
        end[xx][yy] = true;
        int i = 1, e = 1;
        x[1] = xx; y[1] = yy;
        was[xx][yy] = true;
        while (i <= e) {
          for (int j=0;j<4;j++) {
            int xk = x[i]+dx[j];
            int yk = y[i]+dy[j];
            if (xk >= 0 && yk >= 0 && xk < h && yk < w)
              if (a[xk][yk] && !was[xk][yk] && cc[xk][yk] < 63) {
                e++;
                x[e] = xk;
                y[e] = yk;
                was[xk][yk] = true;
              }
          }
          i++;
        }
      }
      int nx = px[xx][yy];
      int ny = py[xx][yy];
      xx = nx; yy = ny;
    }
  }
  int ks = 0;
  for (int ii=0;ii<h;ii++)
    for (int jj=0;jj<w;jj++)
      if (a[ii][jj]) {
        int i = 1, e = 1;
        x[1] = ii; y[1] = jj;
        a[ii][jj] = 0;
        int cnt = (end[ii][jj]);
        while (i <= e) {
          for (int j=0;j<8;j++) {
            int xk = x[i]+dx[j];
            int yk = y[i]+dy[j];
            if (xk >= 0 && yk >= 0 && xk < h && yk < w)
              if (a[xk][yk]) {
                e++;
                x[e] = xk;
                y[e] = yk;
                a[xk][yk] = 0;
                if (end[xk][yk]) cnt++;
              }
          }
          i++;
        }
        s[ks++] = cnt;
      }
  sort(s, s+ks);
  printf("%d\n", ks);
  for (int i=0;i<ks-1;i++) printf("%d ", s[i]);
  if (ks > 0) printf("%d", s[ks-1]);
  printf("\n");
  return 0;
}