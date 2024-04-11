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
#include <cassert>
#include <memory.h>

using namespace std;

const int N = 55555;
const int R = 50;

char s[N];
int f[N][R + 10], p[N][R + 10];
int last[33];
int prev[N][33];
bool mark[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i=0;i<n;i++) s[i] -= 'a';
  for (int j=0;j<26;j++) last[j] = -1;
  for (int i=0;i<=n;i++) {
    for (int j=0;j<26;j++) prev[i][j] = last[j];
    last[s[i]] = i;
  }
  for (int i=0;i<=n;i++)
    for (int j=0;j<=R;j++) f[i][j] = -1, p[i][j] = 0;
  f[0][0] = n;
  for (int i=0;i<n;i++)
    for (int j=0;j<=R;j++) {
      if (f[i][j] == -1) continue;
      if (f[i][j] > f[i+1][j]) {
        f[i+1][j] = f[i][j];
        p[i+1][j] = 0;
      }
      int ft = prev[f[i][j]][s[i]];
      if (ft > f[i+1][j+1]) {
        f[i+1][j+1] = ft;
        p[i+1][j+1] = 1;
      }
    }
  int mx = 0, mi = -1, mj = -1;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=R;j++)
      if (f[i][j] >= i - 1) {
        int len = 2 * j;
        if (f[i][j] == i - 1) len--;
        if (len > mx) {
          mx = len;
          mi = i;
          mj = j;
        }
      }
  for (int i=0;i<n;i++) mark[i] = false;
  int j = mj;
  for (int i=mi;i>0;i--)
    if (p[i][j] == 1) {
      mark[i - 1] = true;
      mark[f[i][j]] = true;
      j--;
    }
  for (int i=0;i<n;i++)
    if (mark[i]) putchar(s[i] + 'a');
  putchar('\n');
  return 0;
}