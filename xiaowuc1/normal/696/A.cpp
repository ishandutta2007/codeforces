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

ll tree[400009];
int n;

ll lca(ll a, ll b) {
  while(a != b) {
    if(a < b) b /= 2;
    else a /= 2;
  }
  return a;
}

unordered_map<ll, ll> cost;

void solve() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int t;
    scanf("%d", &t);
    ll u, v;
    scanf("%lld %lld", &u, &v);
    ll topAnc = lca(u, v);
    if(t == 1) {
      ll inc;
      scanf("%lld", &inc);
      while(u != topAnc) {
        cost[u] += inc;
        u /= 2;
      }
      while(v != topAnc) {
        cost[v] += inc;
        v /= 2;
      }
    }
    else {
      ll ret = 0;
      while(u != topAnc) {
        ret += cost[u];
        u /= 2;
      }
      while(v != topAnc) {
        ret += cost[v];
        v /= 2;
      }
      printf("%lld\n", ret);
    }
  }
}

int main() {
  solve();
  return 0;
}