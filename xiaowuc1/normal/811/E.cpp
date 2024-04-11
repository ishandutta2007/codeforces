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

int find(vector<int>& v, int x) {
  if(v[x] == x) return x;
  return v[x] = find(v, v[x]);
}
bool merge(vector<int>& v, int x, int y) {
  x = find(v, x);
  y = find(v, y);
  if(x == y) return false;
  v[x] = y;
  return true;
}

typedef pair<int, pii> info;
typedef pair<info, vector<int>> state; // state, uf

int r;
const int RAGETREE_SZ = 1 << 17;
state ragetree[2 * RAGETREE_SZ];
int g[10][100000];
state merge(const state& a, const state& b) {
  if(b.first.first == 0) return a;
  assert(sz(a.second) == 2*r);
  assert(sz(b.second) == 2*r);

  assert(b.first.second.first - a.first.second.second == 1);
  state ret;
  ret.first = info(a.first.first + b.first.first, {a.first.second.first, b.first.second.second});
  vector<int> fullpar(4*r);
  for(int i = 0; i < 2*r; i++) fullpar[i] = a.second[i];
  for(int i = 0; i < 2*r; i++) fullpar[i+2*r] = b.second[i]+2*r;
  for(int i = 0; i < r; i++) if(g[i][a.first.second.second] == g[i][b.first.second.first]) {
    int success = merge(fullpar, i+r, i+2*r);
    ret.first.first -= success;
  }
  ret.second.resize(2*r);
  for(int i = 0; i < 2*r; i++) ret.second[i] = i;
  // TODO: optimize this to O(2*c)
  vector<int> cheap(4*r, -1);
  for(int i = 0; i < r; i++) {
    int x = find(fullpar, i);
    if(cheap[x] >= 0) merge(ret.second, i, cheap[x]);
    cheap[x] = i;
    x = find(fullpar, 3*r+i);
    if(cheap[x] >= 0) merge(ret.second, i+r, cheap[x]);
    cheap[x] = i+r;
  }
  return ret;
}

state qry(int lhs, int rhs) {
  state ret;
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  vector<int> lhss, rhss;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      lhss.push_back(lhs);
      break;
    }
    if(lhs%2) lhss.push_back(lhs++);
    if(rhs%2==0) rhss.push_back(rhs--);
    lhs /= 2;
    rhs /= 2;
  }
  reverse(all(rhss));
  assert(sz(lhss) + sz(rhss));
  if(sz(rhss)) {
    ret = ragetree[rhss.back()]; rhss.pop_back();
  }
  else {
    ret = ragetree[lhss.back()]; lhss.pop_back();
  }
  while(sz(rhss)) {
    ret = merge(ragetree[rhss.back()], ret); rhss.pop_back();
  }
  while(sz(lhss)) {
    ret = merge(ragetree[lhss.back()], ret); lhss.pop_back();
  }
  return ret;
}

void solve() {
  int c, q;
  cin >> r >> c >> q;
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> g[i][j];
  for(int j = 0; j < c; j++) {
    vector<int> par(2*r);
    int ans = r;
    for(int a = 0; a < 2*r; a++) par[a] = a%r;
    for(int i = 1; i < r; i++) {
      if(g[i][j] == g[i-1][j]) ans -= merge(par, i-1, i);
    }
    ragetree[RAGETREE_SZ+j].first = info(ans, {j, j});
    ragetree[RAGETREE_SZ+j].second = par;
  }
  for(int i = RAGETREE_SZ-1; i > 0; i--) {
    ragetree[i] = merge(ragetree[2*i], ragetree[2*i+1]);
  }
  while(q--) {
    int a, b;
    cin >> a >> b;
    cout << qry(--a, --b).first.first << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}