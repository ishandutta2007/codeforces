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

const int RAGETREE_SZ = 1 << 18;

int ragetreeinc[2*RAGETREE_SZ];
int ragetreemin[2*RAGETREE_SZ];
int ragetreecnt[2*RAGETREE_SZ];

void apply(int idx, int val) {
  ragetreemin[idx] += val;
  if(idx < RAGETREE_SZ) ragetreeinc[idx] += val;
}
void pushdown(int idx) {
  if(ragetreeinc[idx]) {
    apply(2*idx, ragetreeinc[idx]);
    apply(2*idx+1, ragetreeinc[idx]);
    ragetreeinc[idx] = 0;
  }
}
void pullup(int idx) {
  ragetreemin[idx] = min(ragetreemin[2*idx], ragetreemin[2*idx+1]);
  ragetreecnt[idx] = 0;
  if(ragetreemin[idx] == ragetreemin[2*idx]) ragetreecnt[idx] += ragetreecnt[2*idx];
  if(ragetreemin[idx] == ragetreemin[2*idx+1]) ragetreecnt[idx] += ragetreecnt[2*idx+1];
}

void upd(int idx, int pos, int sz, int lhs, int rhs, int val) {
  int rpos = pos + sz - 1;
  if(pos > rhs || rpos < lhs) return;
  if(pos >= lhs && rpos <= rhs) {
    apply(idx, val);
    return;
  }
  pushdown(idx);
  upd(2*idx, pos, sz/2, lhs, rhs, val);
  upd(2*idx+1, pos + sz/2, sz/2, lhs, rhs, val);
  pullup(idx);
}
void upd(int lhs, int rhs, int val) {
  upd(1, 0, RAGETREE_SZ, lhs, rhs, val);
}

pii qry(int idx, int pos, int sz, int lhs, int rhs) {
  int rpos = pos + sz - 1;
  if(pos > rhs || rpos < lhs) return {1e9, 0};
  if(pos >= lhs && rpos <= rhs) {
    return {ragetreemin[idx], ragetreecnt[idx]};
  }
  pushdown(idx);
  pii a = qry(2*idx, pos, sz/2, lhs, rhs);
  pii b = qry(2*idx+1, pos + sz/2, sz/2, lhs, rhs);
  pullup(idx);
  pii ret = {min(a.first, b.first), 0};
  if(a.first == ret.first) ret.second += a.second;
  if(b.first == ret.first) ret.second += b.second;
  return ret;
}
pii qry(int lhs, int rhs) {
  return qry(1, 0, RAGETREE_SZ, lhs, rhs);
}

vector<int> edges[RAGETREE_SZ];
int start[RAGETREE_SZ];
int sz[RAGETREE_SZ];
int n;

bool isAnc(int i, int j) {
  // i is and of j
  return start[i] < start[j] && start[i] + sz[i] >= start[j] + sz[j];
}

void updateAnc(int i, int j, int delta) {
  assert(isAnc(i, j));
  int lhs = 0;
  int rhs = sz(edges[i])-1;
  while(lhs < rhs) {
    int mid = (lhs+rhs+1)/2;
    if(start[edges[i][mid]] > start[j]) rhs = mid-1;
    else lhs = mid;
  }
  int ic = edges[i][lhs];
  assert(isAnc(ic, j));
  upd(start[ic], start[ic] + sz[ic]-1, delta);
  upd(start[j], start[j] + sz[j]-1, -delta);
}

void updateCross(int i, int j, int delta) {
  upd(0, n-1, delta);
  upd(start[i], start[i] + sz[i]-1, -delta);
  upd(start[j], start[j] + sz[j]-1, -delta);
}

void update(int i, int j, int delta) {
  if(isAnc(i, j)) updateAnc(i, j, delta);
  else if(isAnc(j, i)) updateAnc(j, i, delta);
  else updateCross(i, j, delta);
}

void dfs(int curr, int par, int& idx) {
  start[curr] = idx++;
  sz[curr] = 1;
  if(par >= 0) {
    edges[curr].erase(find(all(edges[curr]), par));
  }
  for(int out: edges[curr]) {
    dfs(out, curr, idx);
    sz[curr] += sz[out];
  }
}

void solve() {
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) ragetreecnt[i+RAGETREE_SZ] = 1;
  for(int i = RAGETREE_SZ-1; i > 0; i--) pullup(i);
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  {
    int idx = 0;
    dfs(1, -1, idx);
  }
  set<pii> present;
  while(q--) {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    if(present.insert({a, b}).second) {
      update(a, b, 1);
    }
    else {
      present.erase({a, b});
      update(a, b, -1);
    }
    pii ret = qry(0, n-1);
    assert(ret.first >= 0);
    if(ret.first == 0) cout << ret.second << "\n";
    else cout << "0\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}