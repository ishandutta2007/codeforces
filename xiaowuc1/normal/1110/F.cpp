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
ll ragetreemin[2 * RAGETREE_SZ];
ll ragetreeinc[2 * RAGETREE_SZ];
void apply(int idx, ll val) {
  ragetreemin[idx] += val;
  if(idx < RAGETREE_SZ) ragetreeinc[idx] += val;
}
void build(int idx) {
  assert(idx >= RAGETREE_SZ);
  while(idx > 1) {
    idx /= 2;
    ragetreemin[idx] = ragetreeinc[idx] + min(ragetreemin[2*idx], ragetreemin[2*idx+1]);
  }
}
void push(int idx) {
  assert(idx >= RAGETREE_SZ);
  for(int x = RAGETREE_DEPTH; x > 0; x--) {
    int p = idx >> x;
    if(ragetreeinc[p]) {
      apply(2*p, ragetreeinc[p]);
      apply(2*p+1, ragetreeinc[p]);
      ragetreeinc[p] = 0;
    }
  }
}
void upd(int lhs, int rhs, ll val) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  int oll = lhs;
  int orr = rhs;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      apply(lhs, val);
      break;
    }
    if(lhs%2) apply(lhs++, val);
    if(rhs%2==0) apply(rhs--, val);
    lhs /= 2;
    rhs /= 2;
  }
  build(oll);
  build(orr);
}
ll qry(int lhs, int rhs) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  push(lhs);
  push(rhs);
  ll ret = 1e18;
  while(lhs <= rhs) {
    if(lhs == rhs) ret = min(ret, ragetreemin[lhs]);
    if(lhs%2) ret = min(ret, ragetreemin[lhs++]);
    if(rhs%2==0) ret = min(ret, ragetreemin[rhs--]);
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

vector<pii> children[RAGETREE_SZ];
int ets[RAGETREE_SZ]; // [ets, ete]
int ete[RAGETREE_SZ];
ll qret[RAGETREE_SZ];
typedef pair<pii, int> query; // <start, end>, idx
vector<query> queries[RAGETREE_SZ];
int n;

void dfssolve(int curr) {
  for(query q: queries[curr]) {
    qret[q.second] = qry(ets[q.first.first], ets[q.first.second]);
  }
  for(pii out: children[curr]) {
    // down this edge
    upd(0, ets[out.first]-1, out.second);
    upd(ets[out.first], ete[out.first], -out.second);
    upd(ete[out.first]+1, n-1, out.second);
    // dfs
    dfssolve(out.first);
    // reverse
    upd(0, ets[out.first]-1, -out.second);
    upd(ets[out.first], ete[out.first], +out.second);
    upd(ete[out.first]+1, n-1, -out.second);
  }
}
void dfsinit(int curr, int& idx) {
  ets[curr] = idx++;
  bool isleaf = true;
  for(pii out: children[curr]) {
    isleaf = false;
    dfsinit(out.first, idx);
    upd(ets[out.first], ete[out.first], out.second);
  }
  if(curr == 1 && sz(children[curr]) == 1) isleaf = true;
  if(!isleaf) upd(ets[curr], ets[curr], 1e18);
  ete[curr] = idx-1;
}
void fill() {
  int idx = 0;
  dfsinit(1, idx);
}

void solve() {
  int q;
  cin >> n >> q;
  for(int i = 2; i <= n; i++) {
    int par, wei;
    cin >> par >> wei;
    children[par].push_back({i, wei});
  }
  for(int i = 0; i < q; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    queries[v].push_back(query({l, r}, i));
  }
  fill();
  dfssolve(1);
  for(int i = 0; i < q; i++) cout << qret[i] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}