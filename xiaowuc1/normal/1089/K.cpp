#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define derr if(1) cerr
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<pii, pii> state;

const int KOOSAGA_SZ = 1 << 20;
ll koosagatree[2 * KOOSAGA_SZ];
ll koosagatreesum[2 * KOOSAGA_SZ];
ll koosagatreelazy[2 * KOOSAGA_SZ];
// also this is range max
// leaf i stores t_i + duration of everything that follows
// if leaf is not valid, then the node has value negative infinity


void inc(int idx, ll val) {
  idx += KOOSAGA_SZ;
  while(idx > 0) {
    koosagatreesum[idx] += val;
    idx /= 2;
  }
}
ll sqry(int lhs, int rhs) {
  ll ret = 0;
  lhs += KOOSAGA_SZ;
  rhs += KOOSAGA_SZ;
  while(lhs <= rhs) {
    if(lhs == rhs) return ret + koosagatreesum[lhs];
    if(lhs%2) ret += koosagatreesum[lhs++];
    if(rhs%2==0) ret += koosagatreesum[rhs--];
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

void apply(int idx, ll val) {
  koosagatree[idx] += val;
  if(idx < KOOSAGA_SZ) koosagatreelazy[idx] += val;
}

void pushdown(int idx) {
  if(koosagatreelazy[idx]) {
    apply(2*idx, koosagatreelazy[idx]);
    apply(2*idx+1, koosagatreelazy[idx]);
    koosagatreelazy[idx] = 0;
  }
}

void pullup(int idx) {
  koosagatree[idx] = max(koosagatree[2*idx], koosagatree[2*idx+1]);
}

void upd(int idx, int start, int sz, int lhs, int rhs, ll val) {
  int end = start + sz - 1;
  if(start > rhs || end < lhs) return;
  if(start >= lhs && end <= rhs) {
    apply(idx, val);
    return;
  }
  pushdown(idx);
  upd(2*idx, start, sz/2, lhs, rhs, val);
  upd(2*idx+1, start + sz/2, sz/2, lhs, rhs, val);
  pullup(idx);
}

void upd(int lhs, int rhs, ll val) {
  // range increment by val
  upd(1, 0, KOOSAGA_SZ, lhs, rhs, val);
}

ll qry(int idx, int start, int sz, int lhs, int rhs) {
  int end = start + sz - 1;
  if(start > rhs || end < lhs) return -1e18;
  if(start >= lhs && end <= rhs) return koosagatree[idx];
  ll ret = -1e18;
  pushdown(idx);
  ret = max(ret, qry(2*idx, start, sz/2, lhs, rhs));
  ret = max(ret, qry(2*idx+1, start + sz/2, sz/2, lhs, rhs));
  pullup(idx);
  return ret;
}

ll qry(int lhs, int rhs) {
  return qry(1, 0, KOOSAGA_SZ, lhs, rhs);
}

pii l[1000000];
void solve() {
  // koosagatree init
  for(int i = 0; i < KOOSAGA_SZ; i++) koosagatree[KOOSAGA_SZ + i] = i;
  for(int i = KOOSAGA_SZ-1; i > 0; i--) pullup(i);
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    string op;
    cin >> op;
    if(op == "?") {
      int t;
      cin >> t;
      cout << qry(0, t)-sqry(t+1,KOOSAGA_SZ-1)-t << "\n";
    }
    else if(op == "+") {
      cin >> l[i].first >> l[i].second;
      upd(0, l[i].first, l[i].second);
      inc(l[i].first, l[i].second);
    }
    else {
      int idx;
      cin >> idx;
      upd(0, l[idx].first, -l[idx].second);
      inc(l[idx].first, -l[idx].second);
    }
  }
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}