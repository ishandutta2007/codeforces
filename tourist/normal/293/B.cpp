#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int md = 1000000007;

int n, m, k;
int ans = 0;
int a[42][42];
int bad[42][42][42];
int res[42][42];
int mp[42];

void go(int row, int col, int mc) {
  if (row == n) {
    for (int c=1;c<=mc;c++)
      for (int qc=c+1;qc<=mc;qc++)
        if (mp[c] != 0 && mp[qc] != 0 && mp[c] == mp[qc]) return;
    int free = 0, cols = k;
    for (int c=1;c<=mc;c++)
      if (mp[c] == 0) free++;
      else cols--;
    int cur = 1;
    for (int c=1;c<=free;c++) {
      cur *= cols;
      cols--;
    }
    ans += cur;
    if (ans >= md) ans -= md;
    return;
  }
  for (int c=1;c<=k && c<=mc+1;c++) {
    if (bad[row][col][c]) continue;
    for (int x=row;x<n;x++)
      for (int y=col;y<m;y++) bad[x][y][c]++;
    res[row][col] = c;
    int ok = 1;
    if (a[row][col] != 0)
      if (mp[c] != 0 && mp[c] != a[row][col]) ok = 0;
    if (ok) {
      bool flag = false;
      if (mp[c] == 0) {
        mp[c] = a[row][col];
        flag = true;
      }
      int nmc = (c > mc ? c : mc);
      if (col < m-1) go(row, col+1, nmc);
      else go(row+1, 0, nmc);
      if (flag) mp[c] = 0;
    }
    for (int x=row;x<n;x++)
      for (int y=col;y<m;y++) bad[x][y][c]--;
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  if (n+m-1 > k) {
    printf("%d\n", 0);
    return 0;
  }
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++) scanf("%d", &a[i][j]);
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      for (int q=1;q<=k;q++) bad[i][j][q] = 0;
  for (int q=1;q<=k;q++) mp[q] = 0;
  go(0, 0, 0);
  printf("%d\n", ans);
  return 0;
}