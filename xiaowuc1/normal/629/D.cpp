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

void update(int index, int l, int r, int should, ll val) {
  if(should < l || should > r) return;
  if(l == r) {
    tree[index] = val;
  }
  else {
    int m = (l+r)/2;
    update(2*index, l, m, should, val);
    update(2*index+1, m+1, r, should, val);
    tree[index] = max(tree[2*index], tree[2*index+1]);
  }
}

void update(int index, ll val) {
  update(1, 0, n-1, index, val);
}

ll query(int index, int l, int r, int lhs, int rhs) {
  if(lhs > r || rhs < l) return 0LL;
  if(l >= lhs && r <= rhs) return tree[index];
  ll ret = 0;
  int m = (l+r)/2;
  ret = max(ret, query(2*index, l, m, lhs, rhs));
  ret = max(ret, query(2*index+1, m+1, r, lhs, rhs));
  return ret;
}

ll query(int l, int r) {
  return query(1, 0, n-1, l, r);
}

typedef pair<ll, int> plli;

plli l[100005];

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int r, h;
    scanf("%d%d", &r, &h);
    l[i] = plli(r*1LL*h*1LL*r, -i);
  }
  sort(l, l+n);
  for(int i = 0; i < n; i++) {
    l[i].second *= -1;
    ll best = query(0, l[i].second-1);
    update(l[i].second, best + l[i].first);
  }
  printf("%.9f\n", query(0, n-1) * PI);
}

int main() {
  solve();
  return 0;
}