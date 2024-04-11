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

const int RAGETREE_DEPTH = 20;
const int RAGETREE_SZ = 1 << RAGETREE_DEPTH;
ll ragetree[2 * RAGETREE_SZ];
ll ragetreelazy[2 * RAGETREE_SZ];

void apply(int idx, ll val) {
  ragetree[idx] += val;
  if(idx < RAGETREE_SZ) ragetreelazy[idx] += val;
}
void build(int idx) {
  assert(idx >= RAGETREE_SZ);
  while(idx > 1) {
    idx /= 2;
    ragetree[idx] = max(ragetree[2*idx], ragetree[2*idx+1]) + ragetreelazy[idx];
  }
}
void push(int idx) {
  assert(idx >= RAGETREE_SZ);
  for(int d = RAGETREE_DEPTH; d > 0; d--) {
    int curr = idx >> d;
    if(ragetreelazy[curr]) {
      apply(2*curr, ragetreelazy[curr]);
      apply(2*curr+1, ragetreelazy[curr]);
      ragetreelazy[curr] = 0;
    }
  }
}
void upd(int lhs, int rhs, ll val) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  int aa = lhs;
  int bb = rhs;
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
  build(aa);
  build(bb);
}
ll qry(int lhs, int rhs) {
  ll ret = 0;
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  while(lhs <= rhs) {
    if(lhs == rhs) return ret + ragetree[lhs];
    if(lhs%2) ret += ragetree[lhs++];
    if(rhs%2==0) ret += ragetree[rhs--];
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

typedef pair<int, pii> event; // x coordinate, <y-coordinate, gain>
typedef pii weapon; // <x, cost>, <y, cost>

event events[200005];
weapon weapons[200005];

void solve() {
  for(int i = RAGETREE_SZ; i < 2 * RAGETREE_SZ; i++) ragetree[i] = -1e15;
  int n, k;
  {
    int m;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
      cin >> weapons[i].first >> weapons[i].second;
    }
    sort(weapons, weapons + n);
    while(m--) {
      int i, v;
      cin >> i >> v;
      i += RAGETREE_SZ;
      ragetree[i] = max(ragetree[i], -(ll)v);
    }
    for(int i = RAGETREE_SZ-1; i >= 0; i--) {
      ragetree[i] = max(ragetree[2*i], ragetree[2*i+1]);
    }
  }
  for(int i = 0; i < k; i++) {
    cin >> events[i].first >> events[i].second.first >> events[i].second.second;
  }
  sort(events, events + k);
  ll ret = -1e18;
  int idx = 0;
  for(int i = 0; i < n; i++) {
    while(idx < k && events[idx].first < weapons[i].first) {
      upd(events[idx].second.first+1, RAGETREE_SZ-1, events[idx].second.second);
      idx++;
    }
    ret = max(ret, qry(0, RAGETREE_SZ-1) - weapons[i].second);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}