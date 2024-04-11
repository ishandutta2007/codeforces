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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

int l[100005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
  }
  l[n+1] = 2e9;
  sort(l, l+n+2);
  int qq;
  scanf("%d", &qq);
  while(qq--) {
    int amt;
    scanf("%d", &amt);
    int leftI = 0;
    int rightI = n+2;
    while(leftI < rightI) {
      int m = (leftI+rightI+1)/2;
      if(l[m] <= amt) {
        leftI = m;
      }
      else {
        rightI = m-1;
      }
    }
    printf("%d\n", leftI);
  }
}

int main() {
  solve();
  return 0;
}