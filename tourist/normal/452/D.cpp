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

int main() {
  int k, n1, n2, n3, t1, t2, t3;
  scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
  vector <int> f1(n1, 0);
  vector <int> f2(n2, 0);
  vector <int> f3(n3, 0);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int p1 = f1[i % n1] + t1 + t2 + t3;
    int p2 = f2[i % n2] + t2 + t3;
    int p3 = f3[i % n3] + t3;
    int p = max(max(p1, p2), p3);
    f1[i % n1] = p - t2 - t3;
    f2[i % n2] = p - t3;
    f3[i % n3] = p;
    ans = p;
  }
  printf("%d\n", ans);
  return 0;
}