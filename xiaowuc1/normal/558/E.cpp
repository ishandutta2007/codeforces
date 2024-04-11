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
typedef pair<ll, ll> pll;

const int SZ = 1 << 17;
class koosagatree {
  vector<int> koosaga, lazy;
  // -1 means delete
  // 0 means nothing
  // 1 means inc
  public:
  koosagatree() {
    koosaga.resize(2 * SZ);
    lazy.resize(2 * SZ);
  } 
  void apply(int idx, int sz, int val) {
    assert(val);
    if(val == -1) {
      koosaga[idx] = 0;
    }
    else {
      koosaga[idx] = sz;
    }
    if(idx < SZ) lazy[idx] = val;
  }
  void pushdown(int idx, int sz) {
    if(lazy[idx]) {
      apply(2*idx, sz/2, lazy[idx]);
      apply(2*idx+1, sz/2, lazy[idx]);
      lazy[idx] = 0;
    }
  }
  void pullup(int idx) {
    koosaga[idx] = koosaga[2*idx] + koosaga[2*idx+1];
  }
  void upd(int idx, int start, int sz, int lhs, int rhs, int delta) {
    int end = start + sz - 1;
    if(start > rhs || end < lhs) return;
    if(start >= lhs && end <= rhs) apply(idx, sz, delta);
    else {
      pushdown(idx, sz);
      upd(2*idx, start, sz/2, lhs, rhs, delta);
      upd(2*idx+1, start + sz/2, sz/2, lhs, rhs, delta);
      pullup(idx);
    }
  }
  void inc(int lhs, int rhs) {
    upd(1, 0, SZ, lhs, rhs, 1);
  }
  void del(int lhs, int rhs) {
    upd(1, 0, SZ, lhs, rhs, -1);
  }
  int qry(int idx, int start, int sz, int lhs, int rhs) {
    int end = start + sz - 1;
    if(start > rhs || end < lhs) return 0;
    if(start >= lhs && end <= rhs) return koosaga[idx];
    int ret = 0;
    pushdown(idx, sz);
    ret += qry(2*idx, start, sz/2, lhs, rhs);
    ret += qry(2*idx+1, start + sz/2, sz/2, lhs, rhs);
    pullup(idx);
    return ret;
  }
  int qry(int lhs, int rhs) {
    return qry(1, 0, SZ, lhs, rhs);
  }
};
koosagatree koosaga[26];

void solve() {
  int n, q;
  cin >> n >> q;
  {
    string s;
    cin >> s;
    for(int i = 0; i < sz(s); i++) koosaga[s[i]-'a'].inc(i,i);
  }
  int amt[26];
  while(q--) {
    int lhs, rhs, k;
    cin >> lhs >> rhs >> k;
    lhs--; rhs--;
    for(int i = 0; i < 26; i++) {
      amt[i] = koosaga[i].qry(lhs, rhs);
      koosaga[i].del(lhs, rhs);
    }
    int start = lhs;
    if(k == 1) {
      for(int i = 0; i < 26; i++) {
        if(amt[i] == 0) continue;
        koosaga[i].inc(start, start + amt[i] - 1);
        start += amt[i];
      }
    }
    else {
      for(int i = 25; i >= 0; i--) {
        if(amt[i] == 0) continue;
        koosaga[i].inc(start, start + amt[i] - 1);
        start += amt[i];
      }
    }
  }
  for(int a = 0; a < n; a++) {
    char ch = 0;
    for(int i = 0; i < 26 && ch == 0; i++) {
      if(koosaga[i].qry(a, a)) ch = 'a' + i;
    }
    assert(ch);
    cout << ch;
  }
  cout << "\n";
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