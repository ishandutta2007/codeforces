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

int n, m, k, good[1111], small[1111], big[1111], i;
char foo[111111];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &m, &k);
  for (i=1;i<=m;i++) good[i] = 0;
  for (i=0;i<k;i++) {
    int qw;
    scanf("%d", &qw);
    good[qw] = 1;
  }
  scanf("%d", &n);
  for (i=0;i<n;i++) {
    int u, w, j;
    scanf("%s", foo);
    scanf("%d", &u);
    int a = 0, b = 0, c = 0;
    for (j=0;j<u;j++) {
      scanf("%d", &w);
      if (w == 0) c++; else
      if (good[w]) a++;
      else b++;
    }
    int ra = k-a, rb = (m-k)-b;
    if (c <= rb) small[i] = a;
    else small[i] = a+(c-rb);
    if (c < ra) big[i] = a+c;
    else big[i] = a+ra;
  }
  for (i=0;i<n;i++) {
    int love = 1, no = 0, j;
    for (j=0;j<n;j++)
      if (i != j) {
        if (small[j] > big[i]) love = 0;
        if (big[j] > small[i]) no = 1;
      }
    if (love && no) printf("%d\n", 2); else
    if (love) printf("%d\n", 0);
    else printf("%d\n", 1);
  }
  return 0;
}