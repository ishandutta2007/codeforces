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

void rsolve() {
  vector<int> a, b;
  int r, c;
  cin >> r >> c;
  a.resize(r);
  b.resize(c);
  vector<string> g;
  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    g.push_back(s);
    for(int j = 0; j < c; j++) {
      if(s[j] == '*') {
        a[i]++;
        b[j]++;
      }
    }
  }
  int ret = r+c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int amt = a[i] + b[j];
      if(g[i][j] == '.') amt++;
      ret = min(ret, r+c-amt);
    }
  }
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) {
    rsolve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}