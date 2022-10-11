#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

const int RAGETREE_DEPTH = 18;
const int RAGETREE_SZ = 1 << RAGETREE_DEPTH;

ll ragetree[2 * RAGETREE_SZ];
ll ragetreelazy[2 * RAGETREE_SZ];

void apply(int idx, ll v) {
  ragetree[idx] += v;
  if(idx < RAGETREE_SZ) ragetreelazy[idx] += v;
}
void build(int idx) {
  assert(idx >= RAGETREE_SZ);
  while(idx > 1) {
    idx /= 2;
    ragetree[idx] = min(ragetree[2*idx], ragetree[2*idx+1]) + ragetreelazy[idx];
  }
}
void push(int idx) {
  for(int d = RAGETREE_DEPTH; d > 0; d--) {
    int v = idx >> d;
    if(ragetreelazy[v]) {
      apply(2*v, ragetreelazy[v]);
      apply(2*v+1, ragetreelazy[v]);
      ragetreelazy[v] = 0;
    }
  }
}
void inc(int lhs, int rhs, ll v) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  int olhs = lhs;
  int orhs = rhs;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      apply(lhs, v);
      break;
    }
    if(lhs%2) apply(lhs++, v);
    if(rhs%2==0) apply(rhs--, v);
    lhs/=2;
    rhs/=2;
  }
  build(olhs);
  build(orhs);
}
ll qry(int lhs, int rhs) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  push(lhs);
  push(rhs);
  ll ret = 1e18;
  while(lhs <= rhs) {
    if(lhs == rhs) return min(ret, ragetree[lhs]);
    if(lhs%2) ret = min(ret, ragetree[lhs++]);
    if(rhs%2==0) ret = min(ret, ragetree[rhs--]);
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

int l[RAGETREE_SZ];
int w[RAGETREE_SZ];
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> l[i];
  for(int i = 1; i <= n; i++) cin >> w[i];
  for(int i = 1; i <= n; i++) {
    inc(l[i], n, w[i]);
  }
  ll ret = 1e18;
  for(int i = 1; i < n; i++) {
    inc(l[i], n, -w[i]);
    inc(0, l[i]-1, w[i]);
    ret = min(ret, qry(0, n));
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}