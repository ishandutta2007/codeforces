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

mt19937 g1;

int g[505][505];

int eval(vector<int>& v) {
  int ret = 0;
  for(int i = 0; i < sz(v); i++) ret ^= g[i][v[i]];
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int uniq = -1;
  for(int i = 0; i < n; i++) {
    set<int> s;
    for(int j = 0; j < m; j++) {
      cin >> g[i][j];
      s.insert(g[i][j]);
    }
    if(sz(s) > 1) uniq = i;
  }
  vector<int> ret;
  ret.resize(n);
  int iter = 0;
  while(iter++ < 1e4) {
    for(int a = 0; a < n; a++) {
      ret[a] = g1();
      ret[a] %= m;
      ret[a] += m;
      ret[a] %= m;
    }
    if(eval(ret)) {
      cout << "TAK\n";
      for(int i = 0; i < n; i++) {
        if(i) cout << " "; cout << (ret[i]+1);
      }
      cout << "\n";
      return;
    }
  }
  cout << "NIE\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}