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
  int n;
  int s = 0;
  int m = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    s += t;
    m = max(m, t);
  }
  printf("%d\n", m*n-s);
  return 0;
}