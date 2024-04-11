#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

double ans[88][88], res[88][88][88], fp[88][88][88], fs[88][88][88];

int main() {
  int n, l[88], r[88];
  scanf("%d", &n);
  for (int i=0;i<n;i++) scanf("%d %d", l+i, r+i);
  vector <int> bounds;
  for (int i=0;i<n;i++) {
    bounds.push_back(l[i]);
    bounds.push_back(r[i]);
  }
  sort(bounds.begin(), bounds.end());
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      for (int k=0;k<n;k++) res[i][j][k] = 0.0;
  int sz = bounds.size();
  for (int q=0;q<sz-1;q++) {
    int st = bounds[q], fin = bounds[q+1];
    if (st == fin) continue;
    int m = 0, c[88];
    double pin[88], pbig[88], psmall[88];
    int add = 0;
    for (int i=0;i<n;i++)
      if (l[i] <= st && fin <= r[i]) {
        m++;
        c[m] = i;
        pin[m] = 1.0 * (fin - st) / (r[i] - l[i]);
        pbig[m] = 1.0 * (st - l[i]) / (r[i] - l[i]);
        psmall[m] = 1.0 - pin[m] - pbig[m];
      } else
      if (r[i] <= st) add++;
    memset(fp, 0, sizeof(fp));
    fp[0][0][0] = 1.0;
    for (int i=0;i<m;i++)
      for (int x=0;x<=i;x++)
        for (int y=0;y<=i-x;y++) {
          double ft = fp[i][x][y];
          fp[i+1][x][y] += ft * psmall[i+1];
          fp[i+1][x][y+1] += ft * pin[i+1];
          fp[i+1][x+1][y] += ft * pbig[i+1];
        }
    memset(fs, 0, sizeof(fs));
    fs[m+1][0][0] = 1.0;
    for (int i=m+1;i>1;i--)
      for (int x=0;x<=m+1-i;x++)
        for (int y=0;y<=m+1-i-x;y++) {
          double ft = fs[i][x][y];
          fs[i-1][x][y] += ft * psmall[i-1];
          fs[i-1][x][y+1] += ft * pin[i-1];
          fs[i-1][x+1][y] += ft * pbig[i-1];
        }
    for (int t=m/2;t>=1;t--) {
      for (int i=t-1;i<m-1;i++) {
        for (int x=0;x<=i+1;x++)
          for (int y=0;y<=i+1-x;y++) fp[i+1][x][y] = 0.0;
        for (int x=0;x<=i;x++)
          for (int y=0;y<=i-x;y++) {
            double ft = fp[i][x][y];
            fp[i+1][x][y] += ft * psmall[i+2];
            fp[i+1][x][y+1] += ft * pin[i+2];
            fp[i+1][x+1][y] += ft * pbig[i+2];
          }
      }
      for (int x=0;x<=m-1;x++)
        for (int y=0;y<=m-1-x;y++) res[c[t]][x+add][y] += pin[t] * fp[m-1][x][y];
    }
    for (int t=m/2+1;t<=m;t++) {
      for (int i=t+1;i>2;i--) {
        for (int x=0;x<=m+2-i;x++)
          for (int y=0;y<=m+2-i-x;y++) fs[i-1][x][y] = 0.0;
        for (int x=0;x<=m+1-i;x++)
          for (int y=0;y<=m+1-i-x;y++) {
            double ft = fs[i][x][y];
            fs[i-1][x][y] += ft * psmall[i-2];
            fs[i-1][x][y+1] += ft * pin[i-2];
            fs[i-1][x+1][y] += ft * pbig[i-2];
          }
      }
      for (int x=0;x<=m-1;x++)
        for (int y=0;y<=m-1-x;y++) res[c[t]][x+add][y] += pin[t] * fs[2][x][y];
    }
  }
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) ans[i][j] = 0.0;
  for (int i=0;i<n;i++)
    for (int x=0;x<n;x++)
      for (int y=0;y<n-x;y++)
        for (int z=0;z<=y;z++) ans[i][x+z] += res[i][x][y] / (y+1);
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) printf("%.6lf ", ans[i][j]);
    printf("\n");
  }
  return 0;
}