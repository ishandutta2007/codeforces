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
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 123456;

vector < pair <int, int> > a[2];
bool b[2][N];
int sz[2];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) {
    int foo, bar, qwe;
    scanf("%d %d %d", &foo, &bar, &qwe);
    a[foo].push_back(make_pair(bar, qwe));
  }
  int ret = 0;
  for (int start = 0; start < 2; start++) {
    for (int t = 0; t < 2; t++) {
      sz[t] = a[t].size();
      for (int i = 0; i < sz[t]; i++) {
        b[t][i] = true;
      }
    }
    int t = start;
    int ans = 0;
    int jump = x;
    while (true) {
      int mx = -1, km = -1;
      for (int i = 0; i < sz[t]; i++) {
        if (b[t][i] && a[t][i].first <= jump) {
          if (a[t][i].second > mx) {
            mx = a[t][i].second;
            km = i;
          }
        }
      }
      if (km == -1) {
        break;
      }
      b[t][km] = false;
      jump += mx;
      ans++;
      t = 1 - t;
    }
    if (ans > ret) {
      ret = ans;
    }
  }
  printf("%d\n", ret);
  return 0;
}