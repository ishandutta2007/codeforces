#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

struct koosaga {
  int sz;
  int rev, swap;
  ll tot;
  koosaga* lhs;
  koosaga* rhs;
};
koosaga* makekoosaga() {
  koosaga* ret = new koosaga;
  memset(ret, 0, sizeof(koosaga));
  return ret;
}

void sanity(koosaga* curr) {
  int idx = __builtin_ctz(curr->sz);
  if(curr->rev & (1 << idx)) {
    swap(curr->lhs, curr->rhs);
    curr->rev ^= 1 << idx;
    if(idx > 1) curr->rev ^= 1 << (idx-1);
  }
  assert(curr->rev < (1<<idx));
  if(curr->swap & (1 << idx)) {
    swap(curr->lhs, curr->rhs);
    curr->swap ^= 1 << idx;
  }
  assert(curr->swap < (1<<idx));
}
void pushdown(koosaga* curr) {
  sanity(curr);
  curr->lhs->rev ^= curr->rev;
  curr->lhs->swap ^= curr->swap;
  curr->rhs->rev ^= curr->rev;
  curr->rhs->swap ^= curr->swap;
  curr->rev = 0;
  curr->swap = 0;
  sanity(curr->lhs);
  sanity(curr->rhs);
}
void pullup(koosaga* curr) {
  assert(curr->rev == 0);
  assert(curr->swap == 0);
  curr->tot = curr->lhs->tot + curr->rhs->tot;
}

koosaga* root;
void init(koosaga* curr, int start, int sz, vector<int>& v) {
  curr->sz = sz;
  if(sz == 1) {
    curr->tot = v[start];
  }  
  else {
    curr->lhs = makekoosaga();
    curr->rhs = makekoosaga();
    init(curr->lhs, start, sz/2, v);
    init(curr->rhs, start + sz/2, sz/2, v);
    pullup(curr);
  }
}

void upd(koosaga* curr, int idx, int val) {
  if(curr->sz == 1) {
    curr->tot = val;
  }
  else {
    pushdown(curr);
    if(idx < curr->lhs->sz) upd(curr->lhs, idx, val);
    else upd(curr->rhs, idx - curr->lhs->sz, val);
    pullup(curr);
  }
}

ll qry(koosaga* curr, int start, int sz, int lhs, int rhs) {
  int end = start + sz - 1;
  if(start > rhs || end < lhs) return 0;
  if(start >= lhs && end <= rhs) return curr->tot;
  ll ret = 0;
  pushdown(curr);
  ret += qry(curr->lhs, start, sz/2, lhs, rhs);
  ret += qry(curr->rhs, start+sz/2, sz/2, lhs, rhs);
  pullup(curr);
  return ret;
}
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v(1<<n);
  for(int i = 0; i < sz(v); i++) cin >> v[i];
  root = makekoosaga();
  init(root, 0, sz(v), v);
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int x, k;
      cin >> x >> k;
      upd(root, --x, k);
      continue;
    }
    if(t == 2) {
      int k;
      cin >> k;
      if(k) {
        root->rev ^= (1 << k);
      }
      sanity(root);
      continue;
    }
    if(t == 3) {
      int k;
      cin >> k;
      root->swap ^= (1 << (k+1));
      sanity(root);
      continue;
    }
    assert(t == 4);
    int lhs, rhs;
    cin >> lhs >> rhs;
    cout << qry(root, 0, 1 << n, --lhs, --rhs) << "\n";
  }
}

 
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}