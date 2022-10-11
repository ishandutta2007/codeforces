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

/*
set<vector<pii>> trees;
int find(vector<int>& v, int x) {
  return v[x] == x ? x : (v[x] = find(v, v[x]));
}
bool merge(vector<int>& v, int x, int y) {
  x = find(v, x);
  y = find(v, y);
  if(x == y) return false;
  v[x] = y;
  return true;
}
bool valid(int n, vector<pii>& tree) {
  vector<int> par;
  for(int i = 0; i < n; i++) par.push_back(i);
  for(pii out: tree) {
    if(!merge(par, out.first, out.second)) return false;
  }
  return true;
}
void dfs(int curr, int cand, int n, vector<pii>& tree) {
  if(curr == n) {
    if(sz(tree) == n-1 && valid(n, tree)) {
      vector<pii> copyv;
      for(pii out: tree) copyv.push_back(out);
      sort(copyv.begin(), copyv.end());
      trees.insert(copyv);
    }
    return;
  }
  if(cand == n) {
    dfs(curr+1, curr+2, n, tree);
    return;
  }
  dfs(curr, cand+1, n, tree);
  tree.push_back({curr, cand});
  if(valid(n, tree)) {
    dfs(curr, cand+1, n, tree);
  }
  tree.pop_back();
}
void countTrees() {
  int n, m;
  cin >> n >> m;
  vector<pii> tree;
  while(m--) {
    int a, b;
    cin >> a >> b;
    tree.push_back({a, b});
  }
  dfs(0, 1, n, tree);
}

void slow() {
  countTrees();
  cout << sz(trees) << endl;
  int first = 0;
  for(auto out: trees) {
    first += out[0] == pii(0, 1);
  }
  cerr << first << endl;
  exit(0);
}
*/

int par[100005];
int sz[100005];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(sz[x] < sz[y]) {
    par[x] = y;
    sz[y] += sz[x];
  }
  else {
    par[y] = x;
    sz[x] += sz[y];
  }
}
void init(int n) {
  for(int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}

void solve() {
  int n, m, mod;
  cin >> n >> m >> mod;
  init(n);
  while(m--) {
    int x, y;
    cin >> x >> y;
    merge(x, y);
  }
  vector<ll> sizes;
  {
    set<int> seen;
    for(int i = 1; i <= n; i++) {
      int x = find(i);
      if(seen.count(x)) continue;
      seen.insert(x);
      sizes.push_back(sz[x]);
    }
  }
  if(sz(sizes) == 1) {
    cout << (1%mod) << "\n";
    return;
  }
  ll ret = 1;
  for(ll out: sizes) {
    ret *= out;
    ret %= mod;
  }
  for(int i = 0; i < sz(sizes)-2; i++) {
    ret *= n;
    ret %= mod;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}