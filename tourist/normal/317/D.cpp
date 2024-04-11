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

const int g[30] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

bool was[66666];

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int tot = n;
  for (int u=2;u*u<=n;u++) was[u] = false;
  for (int u=2;u*u<=n;u++) {
    if (was[u]) continue;
    was[u] = true;
    int x = u, y = 1;
    while ((long long)x*u <= n) {
      x *= u;
      if ((long long)x*x <= n) was[x] = true;
      y++;
    }
    ans ^= g[y];
    tot -= y;
  }
  if (tot & 1) ans ^= 1;
  if (ans > 0) cout << "Vasya" << endl;
  else cout << "Petya" << endl;
  return 0;
}