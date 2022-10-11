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

int l[200005];
int n;

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  for(int i = 0; i < n; i++) {
    if(l[i] % 2 == 1) {
      if(i+1 == n || l[i+1] == 0) {
        printf("NO\n");
        return;
      }
      l[i]--;
      l[i+1]--;
    }
  }
  printf("YES\n");
}

int main() {
  solve();
  return 0;
}