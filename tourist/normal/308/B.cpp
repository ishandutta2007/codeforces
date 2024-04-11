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

const int N = 2222222;

char s[11111111];
int st[N], fin[N], len[N], get[N], nget[N], nx[N];

int main() {
  int n, r, c;
  scanf("%d %d %d", &n, &r, &c);
  c++;
  int total = 0;
  for (int i=0;i<n;i++) {
    char ch = getchar();
    while (ch < 'a' || ch > 'z') ch = getchar();
    len[i] = 1;
    st[i] = total;
    while (ch >= 'a' && ch <= 'z') {
      s[total++] = ch;
      len[i]++;
      ch = getchar();
    }
    fin[i] = total;
  }
  int j = n, sum = 0;
  nx[n] = n;
  for (int i=n-1;i>=0;i--) {
    sum += len[i];
    while (sum > c) {
      j--;
      sum -= len[j];
    }
    nx[i] = j;
  }
  for (int i=0;i<=n;i++) get[i] = i;
  int step = 1 << 30;
  while (step > r) step >>= 1;
  while (step > 0) {
    for (int i=0;i<=n;i++) nget[i] = get[get[i]];
    for (int i=0;i<=n;i++) get[i] = nget[i];
    if (step & r) {
      for (int i=0;i<=n;i++) nget[i] = nx[get[i]];
      for (int i=0;i<=n;i++) get[i] = nget[i];
    }
    step >>= 1;
  }
  int ans = -1, km = -1;
  for (int i=0;i<n;i++)
    if (get[i]-i > ans) {
      ans = get[i]-i;
      km = i;
    }
  sum = 0;
  for (int i=km;i<km+ans;i++) {
    if (sum+len[i] > c) {
      printf("\n");
      sum = 0;
    }
    if (sum > 0) putchar(' ');
    for (int j=st[i];j<fin[i];j++) putchar(s[j]);
    sum += len[i];
  }
  printf("\n");
  return 0;
}