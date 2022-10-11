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

#include <unordered_map>

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

const int RAGETREE_DEPTH = 19;
const int RAGETREE_SZ = 1 << RAGETREE_DEPTH;
int ragetree[2 * RAGETREE_SZ]; // max
int ragetreeinc[2 * RAGETREE_SZ];
void apply(int idx, int val) {
  ragetree[idx] += val;
  if(idx < RAGETREE_SZ) ragetreeinc[idx] += val;
}
void push(int idx) {
  assert(idx >= RAGETREE_SZ);
  for(int d = RAGETREE_DEPTH; d > 0; d--) {
    int x = idx >> d;
    if(ragetreeinc[x]) {
      apply(2*x, ragetreeinc[x]);
      apply(2*x+1, ragetreeinc[x]);
      ragetreeinc[x] = 0;
    }
  }
}
void build(int idx) {
  assert(idx >= RAGETREE_SZ);
  while(idx > 1) {
    idx /= 2;
    ragetree[idx] = ragetreeinc[idx] + max(ragetree[2*idx], ragetree[2*idx+1]);
  }
}
void upd(int lhs, int rhs, int v) {
  if(lhs > rhs) return;
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  int a = lhs;
  int b = rhs;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      apply(lhs, v);
      break;
    }
    if(lhs%2) apply(lhs++, v);
    if(rhs%2==0) apply(rhs--, v);
    lhs /= 2;
    rhs /= 2;
  }
  build(a); build(b);
}
int qry(int lhs, int rhs) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  push(lhs);
  push(rhs);
  int ret = 0;
  while(lhs <= rhs) {
    if(lhs == rhs) return max(ret, ragetree[lhs]);
    if(lhs%2) ret = max(ret, ragetree[lhs++]);
    if(rhs%2==0) ret = max(ret, ragetree[rhs--]);
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

int l[2 * RAGETREE_SZ];
pii rmq[2 * RAGETREE_SZ][RAGETREE_DEPTH];
int n;
pii minqry(int lhs, int rhs) {
  // TODO: optimize to O(1)
  pii ret = {1e9, -1};
  int d = RAGETREE_DEPTH-1;
  while(lhs <= rhs) {
    if(lhs + (1<<d)-1 <= rhs) {
      ret = min(ret, rmq[lhs][d]);
      lhs += (1<<d);
    }
    d--;
  }
  return ret;
}
void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    l[i+n] = l[i];
    rmq[i][0] = {l[i], i};
    rmq[i+n][0] = {l[i+n], i+n};
  }
  for(int d = 1; d < RAGETREE_DEPTH; d++) {
    for(int i = 0; i + (1<<d) <= 2*n; i++) {
      rmq[i][d] = min(rmq[i][d-1], rmq[i+(1<<(d-1))][d-1]);
    }
  }
  queue<pii> q;
  q.push({0, n-1});
  while(sz(q)) {
    pii curr = q.front(); q.pop();
    if(curr.first >= curr.second) continue;
    pii best = minqry(curr.first, curr.second);
    upd(curr.first, best.second-1, 1);
    upd(best.second+1, curr.second, 1);
    q.push({curr.first, best.second-1});
    q.push({best.second+1, curr.second});
  }
  int lowdepth = qry(0, n-1);
  int shift = 0;
  for(int i = 0; i < n-1; i++) {
    int ni = i + n;
    if(l[i] == 1) {
      // the root has moved, nothing changes
    }
    else {
      // see what things on the left elevate
      int lhs = i;
      int rhs = ni-1;
      while(lhs < rhs) {
        int mid = (lhs+rhs+1)/2;
        if(minqry(i, mid).second == i) lhs = mid;
        else rhs = mid-1;
      }
      // anc is at lhs, lhs is the rightmost smallest
      upd(i+1, lhs, -1);
      // see what things on the right get shoved down
      lhs = i+1;
      rhs = ni;
      while(lhs < rhs) {
        int mid = (lhs+rhs)/2;
        if(minqry(mid, ni).second == ni) rhs = mid;
        else lhs = mid+1;
      }
      // anc is at lhs-1 again
      upd(ni, ni, qry(lhs-1, lhs-1));
      upd(lhs, ni, 1);
    }
    int canddepth = qry(i+1, i+n);
    if(canddepth < lowdepth) {
      lowdepth = canddepth;
      shift = i+1;
    }
  }
  cout << lowdepth+1 << " " << shift << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}