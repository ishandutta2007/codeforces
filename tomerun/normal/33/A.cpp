#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

using namespace std;

int n, m, k;
vector<int> v;

void solve(){
  int r,c;
  for (int i = 0; i < n; ++i) {
    cin >> r >> c;
    v[r-1] = min(v[r-1], c);
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    ans += v[i];
  }
  cout << min(ans, k);
}

int main(){
   cin >> n >> m >> k;
   v.assign(m, 100000000);
   solve();
  return 0;
}