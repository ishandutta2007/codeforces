#include <algorithm>
#include <bitset>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <sys/time.h>

using namespace std;

int solve() {
  int n;
  cin >> n;
  int prev = -1;
  int ans = 0;
  int x;
  bool dup = false;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x == prev) {
      dup = true;
    } else if (x == prev + 1) {
      ans++;
    } else {
      ans++;
      if (dup) {
        ans++;
        dup = false;
      }
    }
    prev = x;
  }
  if (dup) ans++;
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << solve() << endl;
  }
}