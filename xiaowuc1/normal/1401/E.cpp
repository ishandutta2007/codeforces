#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

const int SZ = 1 << 20;
int koosagatree[2 * SZ];
void upd(int idx, int val) {
  idx += SZ;
  koosagatree[idx] += val;
  while(idx > 1) {
    idx /= 2;
    koosagatree[idx] = koosagatree[2*idx] + koosagatree[2*idx+1];
  }
}
int qry(int lhs, int rhs) {
  lhs += SZ;
  rhs += SZ;
  int ret = 0;
  while(lhs <= rhs) {
    if(lhs%2) ret += koosagatree[lhs++];
    if(rhs%2==0) ret += koosagatree[rhs--];
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

vector<pii> query[1000000];
vector<int> insert[1000000];
vector<int> rem[1000000];
void solve() {
  int h, v;
  cin >> h >> v;
  upd(0, 1);
  upd(1e6, 1);
  while(h--) {
    int y, lhs, rhs;
    cin >> y >> lhs >> rhs;
    if(lhs == 0) query[y].emplace_back(lhs, rhs);
    else query[y].emplace_back(lhs, rhs);
  }
  ll ret = 1;
  while(v--) {
    int x, lhs, rhs;
    cin >> x >> lhs >> rhs;
    if(lhs == 0 && rhs == 1e6) {
      upd(x, 1);
      ret++;
      continue;
    }
    if(lhs == 0) {
      upd(x, 1);
      rem[rhs].push_back(x);
    }
    else insert[lhs].push_back(x);
  }
  for(int y = 1; y < 1000000; y++) {
    // insert, then query, then delete
    for(int out: insert[y]) upd(out, 1);
    for(pii out: query[y]) ret += qry(out.f, out.s) - 1;
    for(int out: rem[y]) upd(out, -1);
  }
  cout << ret << "\n";
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