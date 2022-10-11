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

// will richard ever know?
const int SZ = 1 << 20;
int tree[SZ];
void upd(int idx) {
  int val = idx;
  while(idx < SZ) {
    tree[idx] = max(tree[idx], val);
    idx += idx & -idx;
  }
}
int qry(int rhs) {
  int ret = 0;
  while(rhs) {
    ret = max(ret, tree[rhs]);
    rhs -= rhs & -rhs;
  }
  return ret;
}
 
// longest streak
int maxlen[1000005];
int val(char ch, char r) {
  if(ch == '?') return r;
  return ch;
}
vector<int> events[1000005];
int ans[1000005];
void solve() {
  set<int> good;
  int n;
  string s;
  cin >> n >> s;
  for(char ch = '0'; ch <= '1'; ch++) {
    for(int i = 0; i < n;) {
      int j = i+1;
      while(j < n && val(s[i], ch) == val(s[j], ch)) j++;
      for(int k = i; k < j; k++) maxlen[k+1] = max(maxlen[k+1], k-i+1);
      i = j;
    }
  }
  for(int i = 1; i <= n; i++) events[maxlen[i]].push_back(i);
  for(int i = 0; i < n; i++) good.insert(i);
  ans[1] = n;
  for(int len = n; len >= 2; len--) {
    for(int out: events[len]) {
      upd(out);
    }
    int rhs = n;
    int amt = 0;
    while(rhs) {
      rhs = qry(rhs) - len;
      if(rhs < 0) break;
      amt++;
    }
    ans[len] = amt;
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i==n];
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