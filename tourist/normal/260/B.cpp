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
#include <memory.h>

using namespace std;

const int kd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n, i, j;
char s[555555];
int cnt[42][42][42];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%s", s);
  int n = strlen(s);
  int mx = 0, ad = 0, am = 0, ay = 0;
  memset(cnt, 0, sizeof(cnt));
  for (i=0;i+9<n;i++) {
    if (s[i+2] != '-' || s[i+5] != '-') continue;
    int ok = 1;
    for (j=0;j<10;j++)
      if (j != 2 && j != 5 && s[i+j] == '-') ok = 0;
    if (!ok) continue;
    int dd = (s[i]-48)*10+(s[i+1]-48);
    int mm = (s[i+3]-48)*10+(s[i+4]-48);
    if (s[i+6] != '2' || s[i+7] != '0' || s[i+8] != '1') continue;
    int yy = s[i+9]-48;
    if (yy < 3 || yy > 5) continue;
    if (mm < 1 || mm > 12) continue;
    if (dd < 1 || dd > kd[mm]) continue;
    cnt[dd][mm][yy]++;
    if (cnt[dd][mm][yy] > mx) {
      mx = cnt[dd][mm][yy];
      ad = dd, am = mm, ay = yy;
    }
  }
  printf("%d%d-%d%d-%d\n", ad/10, ad%10, am/10, am%10, 2010+ay);
  return 0;
}