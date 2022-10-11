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
typedef pair<int, int> pii;

int main() {
  int n;
  scanf("%d", &n);
  n %= 6;
  int x;
  scanf("%d", &x);
  for(int i = n; i >= 1; i--) {
    if(i%2) {
      if(x != 2) {
        x = 1-x;
      }
    }
    else {
      if(x != 0) {
        x = 3-x;
      }
    }
  }
  printf("%d\n", x);
}