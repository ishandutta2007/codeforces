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

bool has(vector <int> v, int x) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    if (v[i] == x) return true;
  }
  return false;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  map < int, vector <int> > mp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    mp[x].push_back(y);
    mp[y].push_back(x);
  }
  map <int, vector <int> >::iterator i = mp.begin();
  while (i != mp.end()) {
    printf("%d: ", (*i).first);
    vector <int> fr = (*i).second;
    sort(fr.begin(), fr.end());
    vector <int> ret;
    map <int, vector <int> >::iterator j = mp.begin();
    while (j != mp.end()) {
      if ((*j).first == (*i).first || has(fr, (*j).first)) {
        j++;
        continue;
      }
      vector <int> fj = (*j).second;
      int cnt = 0;
      for (int q = 0; q < (int)fj.size(); q++) {
        if (has(fr, fj[q])) {
          cnt++;
        }
      }
      if (cnt * 100 >= (int)fr.size() * k) {
        ret.push_back((*j).first);
      }
      j++;
    }
    sort(ret.begin(), ret.end());
    int sz = ret.size();
    printf("%d", sz);
    for (int j = 0; j < sz; j++) printf(" %d", ret[j]);
    printf("\n");
    i++;
  }
  return 0;
}