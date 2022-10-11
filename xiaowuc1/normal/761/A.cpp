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
  int a, b;
  scanf("%d%d", &a, &b);
  bool valid = false;
  if(a > 0 || b > 0) {
    valid |= a == b;
    valid |= a == b-1;
    valid |= a == b+1;
  }
  if(valid) printf("YES\n");
  else printf("NO\n");
  return 0;
}