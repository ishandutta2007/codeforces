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

int x[50];

int solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> h(100);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      h[x[i] - x[j]] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < h.size(); ++i) {
    ans += h[i];
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << solve() << endl;
  }
}