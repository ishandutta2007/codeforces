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
typedef pair<int, pii> pipii;

const int MOD = 1000000007;

int l[500005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
  }
  int ret = 0;
  l[n+1] = l[n];
  for(int i = 1; i <= n; ) {
    if(l[i] == l[i+1]) {
      i++;
      continue;
    }
    int j = i+1;
    while(j <= n && l[j] != l[j+1]) {
      j++;
    }
    ret = max(ret, (j-i)/2);
    int a = i+1;
    int b = j-1;
    while(a <= b) {
      l[a] = l[a-1];
      l[b] = l[b+1];
      a++;
      b--;
    }
    i = j;
  }

  printf("%d\n", ret);
  for(int i = 1; i <= n; i++) {
    printf("%d", l[i]);
    if(i == n) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}