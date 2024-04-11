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


int main(){
  int n;
  scanf("%d", &n);
  int last[100001] = {};
  for(int i = 0; i < sizeof(last) / sizeof(last[0]); ++i) {
    last[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    int x,y;
    scanf("%d %d", &x, &y);
    int count = 0;
    for (int j = 1; j*j <= x; ++j) {
      if(x % j == 0) {
	if (last[j] < i - y) ++count;
	int o = x / j;
	if(o != j) {
	  if (last[o] < i - y) ++count;
	}
	last[j] = i;
	last[o] = i;
      }
    }
    cout << count << endl;
  }
  return 0;
}