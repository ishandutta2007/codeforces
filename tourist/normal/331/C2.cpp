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
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef pair <long long, int> pp;

map <pp, pp> mp;

pp go(long long v, int mx) {
  if (v == 0) return make_pair(0, 0);
  if (v < 10) {
    pp ans = make_pair(1, 0);
    if (v < mx) ans.second = (mx-v);
    return ans;
  }
  pp state = make_pair(v, mx);
  if (mp.find(state) != mp.end()) return mp[state];
  long long step = 1;
  while (step <= v/10) step *= 10;
  pp ans = make_pair(0, 0);
  while (true) {
    int dig = v/step;
    int newmx = mx;
    if (dig > newmx) newmx = dig;
    pp cur = go(v % step, newmx);
    ans.first += cur.first;
    v -= v % step;
    if (cur.second > 0) v -= cur.second; else {
      v -= newmx;
      if (newmx > 0) ans.first++;
    }
    if (dig == 0) break;
  }
  ans.second = -v;
  mp[state] = ans;
  return ans;
}

int main() {
  long long n;
  cin >> n;
  mp.clear();
  pp result = go(n, 0);
  cout << result.first << endl;
  return 0;
}