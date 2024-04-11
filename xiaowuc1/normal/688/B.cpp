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

const double PI = 2 * acos(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

const int MOD = 1000000007;

char buf[100005];

void solve() {
  gets(buf);
  int len = strlen(buf);
  for(int i = 0; i < len; i++) {
    printf("%c", buf[i]);
  }
  for(int i = 0; i < len; i++) {
    printf("%c", buf[len-1-i]);
  }
  printf("\n");
}

int main() {
  solve();
  return 0;
}