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

char s[424242];
int cnt[424];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i=32;i<256;i++) cnt[i] = 0;
  for (int i=0;i<n;i++) cnt[s[i]]++;
  int len;
  scanf("%d", &len);
  int ll = 1, rr = n + 1;
  while (ll < rr) {
    int mid = (ll + rr) >> 1;
    int need = 0;
    for (int i=32;i<256;i++) need += (cnt[i] + mid - 1) / mid;
    if (need <= len) rr = mid;
    else ll = mid + 1;
  }
  if (ll == n + 1) {
    printf("%d\n", -1);
    return 0;
  }
  int mid = ll;
  printf("%d\n", mid);
  int need = 0;
  for (int i=32;i<256;i++) {
    int needhere = (cnt[i] + mid - 1) / mid;
    for (int j=0;j<needhere;j++) {
      need++;
      putchar(i);
    }
  }
  while (need < len) {
    putchar('a');
    need++;
  }
  return 0;
}