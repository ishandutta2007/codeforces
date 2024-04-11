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

const int N = 2222;

int f[N][N], len[N], can[N][N], cc[N];
char s[N], p[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  memset(f, 0, sizeof(f));
  for (int i=n-1;i>=0;i--)
    for (int j=n-1;j>=0;j--)
      if (s[i] == s[j]) f[i][j] = f[i+1][j+1]+1;
      else f[i][j] = 0;
  len[0] = 1;
  for (int i=1;i<n;i++) {
    len[i] = 1;
    for (int j=0;j<i;j++)
      if (f[i][j]+1 > len[i]) len[i] = f[i][j]+1;
  }
  for (int i=0;i<n;i++)
    for (int j=len[i];j<=n-i;j++) can[i][j] = 1;
  int m;
  scanf("%d", &m);
  for (int q=0;q<m;q++) {
    scanf("%s", p);
    int ll, rr;
    scanf("%d %d", &ll, &rr);
    int k = strlen(p);
    memset(f, 0, sizeof(f));
    for (int i=n-1;i>=0;i--)
      for (int j=k-1;j>=0;j--)
        if (s[i] == p[j]) f[i][j] = f[i+1][j+1]+1;
        else f[i][j] = 0;
    for (int i=0;i<n;i++) {
      for (int j=0;j<=n;j++) cc[j] = 0;
      for (int j=0;j<k;j++) cc[f[i][j]]++;
      for (int j=n;j>0;j--) cc[j-1] += cc[j];
      for (int j=1;j<=n;j++)
        if (cc[j] >= ll && cc[j] <= rr) ;
        else can[i][j] = 0;
    }
  }
  int ans = 0;
  for (int i=0;i<n;i++)
    for (int j=len[i];j<=n-i;j++) ans += can[i][j];
  printf("%d\n", ans);
  return 0;
}