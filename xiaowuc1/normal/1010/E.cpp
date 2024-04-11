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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<int> vi;
typedef bitset<1000> bs;

// NO SAD

const int UPD = 0;
const int QRY = 1;
struct state {
  int x, y, z;
  int idx;
  int type;
  state(int xx, int yy, int zz, int ii, int tt) {
    x=xx; y=yy; z=zz; idx=ii; type=tt;
    assert(type == UPD || type == QRY);
  }
};

const int RAGETREE_SZ = 1 << 19;
const int COORD_OFFSET = 100000;
int minragetree[2 * RAGETREE_SZ];
void upd(int idx, int val) {
  // set l[idx] to max(l[idx], val)
  idx += COORD_OFFSET + RAGETREE_SZ;
  if(val >= minragetree[idx]) return;
  minragetree[idx] = val;
  while(idx > 1) {
    if(minragetree[idx/2] <= minragetree[idx]) return;
    minragetree[idx/2] = minragetree[idx];
    idx /= 2;
  }
}
int qry(int lhs, int rhs) {
  lhs += COORD_OFFSET + RAGETREE_SZ;
  rhs += COORD_OFFSET + RAGETREE_SZ;
  int ret = 1e9;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      ret = min(ret, minragetree[lhs]);
      break;
    }
    if(lhs%2) ret = min(ret, minragetree[lhs++]);
    if(rhs%2==0) ret = min(ret, minragetree[rhs--]);
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

int ret[100005];
const int OPEN = 1;
const int CLOSED = 2;

bool statecmp(state a, state b) {
  // sort in increasing order of x
  if(a.x != b.x) return a.x < b.x;
  if(a.y != b.y) return a.y < b.y;
  if(a.z != b.z) return a.z < b.z;
  return a.type < b.type;
}

void analyze(int xl, int yl, int zl, int xr, int yr, int zr, vector<state>& v) {
  sort(v.begin(), v.end(), statecmp);
  for(int i = 0; i < 2*RAGETREE_SZ; i++) {
    minragetree[i] = 1e9;
  }
  for(state out: v) {
    if(out.x < xl || out.y < yl || out.z < zl) continue;
    if(out.type == UPD) {
      upd(out.y, out.z);
    }
    else {
      if(qry(-1e5, out.y) <= out.z) {
        ret[out.idx] = CLOSED;
      }
    }
  }
}

void solve() {
  int _; cin >> _; cin >> _; cin >> _;
  int good, bad, query;
  cin >> good >> bad >> query;
  int xl = 1e6; int xr = 0;
  int yl = 1e6; int yr = 0;
  int zl = 1e6; int zr = 0;
  while(good--) {
    int x, y, z; cin >> x >> y >> z;
    xl = min(xl, x); xr = max(xr, x);
    yl = min(yl, y); yr = max(yr, y);
    zl = min(zl, z); zr = max(zr, z);
  }
  vector<state> badV;
  for(int i = 0; i < bad; i++) {
    int x, y, z; cin >> x >> y >> z;
    if(x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) {
      cout << "INCORRECT\n";
      return;
    }
    badV.push_back(state(x, y, z, -1, UPD));
  }
  cout << "CORRECT\n";
  for(int i = 0; i < query; i++) {
    int x, y, z; cin >> x >> y >> z;
    if(x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) {
      ret[i] = OPEN;
      continue;
    }
    badV.push_back(state(x, y, z, i, QRY));
  }
  for(int mask = 0; mask < 8; mask++) {
    if(mask & 1) { swap(xl, xr); xl *= -1; xr *= -1; for(state& out: badV) out.x *= -1; }
    if(mask & 2) { swap(yl, yr); yl *= -1; yr *= -1; for(state& out: badV) out.y *= -1; }
    if(mask & 4) { swap(zl, zr); zl *= -1; zr *= -1; for(state& out: badV) out.z *= -1; }
    analyze(xl, yl, zl, xr, yr, zr, badV);
    if(mask & 1) { swap(xl, xr); xl *= -1; xr *= -1; for(state& out: badV) out.x *= -1; }
    if(mask & 2) { swap(yl, yr); yl *= -1; yr *= -1; for(state& out: badV) out.y *= -1; }
    if(mask & 4) { swap(zl, zr); zl *= -1; zr *= -1; for(state& out: badV) out.z *= -1; }
  }
  for(int i = 0; i < query; i++) {
    if(ret[i] == OPEN) cout << "OPEN\n";
    else if(ret[i] == CLOSED) cout << "CLOSED\n";
    else {
      assert(ret[i] == 0);
      cout << "UNKNOWN\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}