#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

int l[250000];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  sort(l, l+n);
  int ret = (int)(2.1e9);
  int amt = 0;
  for(int i = 0; i < n-1; i++) {
    if(l[i+1] - l[i] < ret) {
      ret = l[i+1] - l[i];
      amt = 0;
    }
    if(l[i+1] - l[i] == ret) {
      amt++;
    }
  }
  printf("%d %d\n", ret, amt);
}