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

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int r = 0;
  for(int i = 1; i <= c; i++) {
    if(i%a == 0 && i%b == 0) r++;
  }
  printf("%d\n", r);
  return 0;
}