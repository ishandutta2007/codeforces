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
typedef vector<vector<int>> matrix;

int r, c;

int solve(matrix m, vector<int> reference) {
  int ret = 0;
  for(auto out: m) {
    int x = 0;
    for(int i = 0; i < sz(reference); i++) {
      x += reference[i] == out[i];
    }
    ret += min(x, sz(reference)-x);
  }
  return ret;
}

int solve(matrix m) {
  vector<int> t;
  t.resize(sz(m[0]));
  int ret = solve(m, t);
  for(auto out: m) {
    ret = min(ret, solve(m, out));
  }
  return ret;
}

matrix transpose(matrix m) {
  matrix ret;
  for(int j = 0; j < sz(m[0]); j++) {
    vector<int> t;
    for(int i = 0; i < sz(m); i++) t.push_back(m[i][j]);
    ret.push_back(t);
  }
  return ret;
}

void solve() {
  int k;
  cin >> r >> c >> k;
  matrix m;
  for(int i = 0; i < r; i++) {
    vector<int> t;
    for(int j = 0; j < c; j++) {
      int x;
      cin >> x;
      t.push_back(x);
    }
    m.push_back(t);
  }
  int ret = 1e9;
  ret = min(ret, solve(m));
  ret = min(ret, solve(transpose(m)));
  if(ret > k) ret = -1;
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}