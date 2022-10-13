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

struct node {
  int trans[5][5];
};

node init(char ch) {
  node ret;
  memset(ret.trans, 1, sizeof(ret.trans));
  for(int i = 0; i < 5; i++) ret.trans[i][i] = 0;
  if(ch == '2') {
    ret.trans[0][0] = 1;
    ret.trans[0][1] = 0;
  }
  if(ch == '0') {
    ret.trans[1][1] = 1;
    ret.trans[1][2] = 0;
  }
  if(ch == '1') {
    ret.trans[2][2] = 1;
    ret.trans[2][3] = 0;
  }
  if(ch == '7') { // good
    ret.trans[3][3] = 1;
    ret.trans[3][4] = 0;
  }
  if(ch == '6') { // bad
    ret.trans[3][3] = 1;
    ret.trans[4][4] = 1;
  }
  return ret;
}

node merge(const node& a, const node& b) {
  node ret;
  memset(ret.trans, 1, sizeof(ret.trans));
  for(int i = 0; i < 5; i++) for(int j = i; j < 5; j++) for(int k = i; k <= j; k++) {
    ret.trans[i][j] = min(ret.trans[i][j], a.trans[i][k] + b.trans[k][j]);
  }
  return ret;
}

const int RAGETREE_SZ = 1 << 18;
node ragetree[2 * RAGETREE_SZ];
node qry(int lhs, int rhs) {
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  vector<int> lv, rv;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      lv.push_back(lhs);
      break;
    }
    if(lhs%2) lv.push_back(lhs++);
    if(rhs%2==0) rv.push_back(rhs--);
    lhs /= 2;
    rhs /= 2;
  }
  reverse(all(rv));
  assert(sz(lv) + sz(rv));
  node init;
  if(sz(rv)) {
    init = ragetree[rv.back()]; rv.pop_back();
  }
  else {
    assert(sz(lv));
    init = ragetree[lv.back()]; lv.pop_back();
  }
  while(sz(rv)) {
    init = merge(ragetree[rv.back()], init); rv.pop_back();
  }
  while(sz(lv)) {
    init = merge(ragetree[lv.back()], init); lv.pop_back();
  }
  return init;
}

void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  for(int i = 0; i < sz(s); i++) {
    ragetree[i + RAGETREE_SZ] = init(s[i]);
  }
  for(int i = RAGETREE_SZ-1; i > 0; i--) {
    ragetree[i] = merge(ragetree[2*i], ragetree[2*i+1]);
  }
  while(q--) {
    int lhs, rhs;
    cin >> lhs >> rhs;
    node ret = qry(--lhs, --rhs);
    if(ret.trans[0][4] > n) cout << "-1\n";
    else cout << ret.trans[0][4] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}