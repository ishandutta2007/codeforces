#include <algorithm>
#include <array>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

const int SZ = 1 << 20;
int tree[2 * SZ];
void upd(int idx, int val) {
  idx += SZ;
  tree[idx] = val;
  while(idx > 1) {
    idx /= 2;
    tree[idx] = tree[2*idx] + tree[2*idx+1];
  }
}
int qry(int lhs, int rhs) {
  lhs += SZ;
  rhs += SZ;
  int ret = 0;
  while(lhs <= rhs) {
    if(lhs%2) ret += tree[lhs++];
    if(rhs%2==0) ret += tree[rhs--];
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}
deque<int> locs[51];
void solve() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    int c;
    cin >> c;
    locs[c].pb(500000 + i);
    upd(locs[c].back(), 1);
  }
  int ni = 499999;
  for(int qq = 0; qq < q; qq++) {
    int c;
    cin >> c;
    int use = locs[c].front();
    locs[c].pop_front();
    locs[c].push_front(ni--);
    cout << qry(0, use) << " \n"[qq == q-1];
    upd(use, 0);
    upd(locs[c].front(), 1);
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