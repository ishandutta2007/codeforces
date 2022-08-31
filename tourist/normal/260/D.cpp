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

int n, i;
int c[111111], s[111111];
set < pair<int, int> > a[2];
set < pair<int, int> >::iterator it;

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d", &n);
  for (i=0;i<n;i++) {
    scanf("%d %d", c+i, s+i);
    a[c[i]].insert(make_pair(s[i], i+1));
  }
  while (a[0].size()+a[1].size() > 1) {
    it = a[0].begin();
    int mn = (*it).first, id = (*it).second;
    it = a[1].begin();
    if ((*it).first < mn && a[1].size() > 1 || a[0].size() == 1) {
      mn = (*it).first;
      id = (*it).second;
      it = a[0].end();
      it--;
      printf("%d %d %d\n", id, (*it).second, mn);
      int q1 = (*it).first, q2 = (*it).second;
      a[1].erase(a[1].begin());
      a[0].erase(it);
      a[0].insert(make_pair(q1-mn, q2));
    } else {
      it = a[1].end();
      it--;
      printf("%d %d %d\n", id, (*it).second, mn);
      int q1 = (*it).first, q2 = (*it).second;
      a[0].erase(a[0].begin());
      a[1].erase(it);
      a[1].insert(make_pair(q1-mn, q2));
    }
  }
  return 0;
}