#include <vector>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include "myutil.hpp"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll INF = 1ll << 60;

int solve(int w, int h){
  vector<int> cur(1 << (2 *w), -1);
  cur[0] = 0;
  for (int i = 0; i < h; ++i) {
    vector<int> next(1 << (2 *w), -1);
    for(size_t j = 0; j < (1 << (2*w)); ++j) {
      if (cur[j] == -1) continue;
      int up = (j & ((1 << w) - 1));
      for (int k = 0; k < (1 << w); ++k) {
	if (i != 0){
	  if((up | k) != ((1 << w) - 1)) continue;
	}
	int v = j >> w;
	int count = 0;
	for (int l = 0; l < w; ++l) {
	  if (k & (1 << l)) {
	    ++count;
	    v |= (1 << l);
	    v |= (1 << (w+l));
	    if (l != 0) v |= (1 << (l-1));
	    if (l != w-1) v |= (1 << (l+1));
	  }
	}
	if(next[v] == -1 || next[v] > cur[j] + count) {
	  next[v] = cur[j] + count;
	}
      }
    }
    swap(cur, next);
//     for (size_t t = 0; t < cur.size(); ++t) {
//       cout << cur[t] << " ";
//     }
//     cout << endl;
  }
  int ans = 1000;
  for (size_t i = 0; i < (1 << w); ++i) {
    int idx = (i << w) + ((1 << w) - 1);
    if (cur[idx] != -1 && cur[idx] < ans) ans = cur[idx];
  }
  return w*h - ans;
}

int main(){
  int x,y;
  cin >> x >> y;
  if (x > y) swap(x,y);
  cout << solve(x, y) << endl;
}