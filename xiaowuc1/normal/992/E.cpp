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
typedef pair<ll, ll> pll;

const int RAGETREE_SZ = 1 << 18;
ll bit[RAGETREE_SZ];
void bitupd(int idx, int val) {
  while(idx < RAGETREE_SZ) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
ll bitqry(int idx) {
  ll ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

pii ragetree[2 * RAGETREE_SZ]; // <val, idx>
void upd(int i, int v) {
  i += RAGETREE_SZ;
  ragetree[i] = {v, i-RAGETREE_SZ};
  while(i > 1) {
    i /= 2;
    ragetree[i] = max(ragetree[2*i], ragetree[2*i+1]);
  }
}
const pii BAD = {-1e9, -1e9};
pii qry(int idx, int pos, int sz, int lhs, int rhs, ll v) {
  // want smallest index >= v
  int rpos = pos + sz - 1;
  if(rhs < pos || lhs > rpos) return BAD;
  if(ragetree[idx].first < v) return BAD;
  if(pos == rpos) {
    return ragetree[idx];
  }
  pii ret = qry(2*idx, pos, sz/2, lhs, rhs, v);
  if(ret.first >= v) return ret;
  return qry(2*idx+1, pos+sz/2, sz/2, lhs, rhs, v);
}
pii qry(int lhs, int rhs, ll v) {
  return qry(1, 0, RAGETREE_SZ, lhs, rhs, v);
}

int val[RAGETREE_SZ];
int n;
void solve() {
  int q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> val[i];
    bitupd(i, val[i]);
    upd(i, val[i]);
  }
  while(q--) {
    int i, v;
    cin >> i >> v;
    bitupd(i, v-val[i]);
    val[i] = v;
    upd(i, val[i]);
    int ret = val[1] == 0 ? 1 : -1;
    ll currprefsum = bitqry(1);
    int lhsidx = 2;
    while(ret < 0 && currprefsum <= 1e9 && lhsidx <= n) {
      pii cand = qry(lhsidx, n, currprefsum);
      if(cand.first < currprefsum) break;
      int idx = cand.second;
      if(bitqry(idx-1) == val[idx]) {
        ret = idx;
        break;
      }
      lhsidx = idx+1;
      currprefsum = bitqry(lhsidx-1);
    }
    cout << ret << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}