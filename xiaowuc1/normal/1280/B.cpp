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

inline bool allA(string& s, int lhs, int rhs) {
  for(int i = lhs; i <= rhs; i++) if(s[i] != 'A') return false;
  return true;
}

inline bool allA(string& s) {
  return allA(s, 0, sz(s)-1);
}

int solve(vector<string>& g) {
  // we only care about rows
  int ret = 4;
  {
    // 1 case
    if(allA(g[0]) || allA(g.back())) return 1;
  }
  {
    // 2 case
    for(int i = 0; i < sz(g); i++) if(allA(g[i])) return 2;
    if(g[0][0] == 'A') return 2;
    if(g[0][sz(g[0])-1] == 'A') return 2;
    if(g[sz(g)-1][0] == 'A') return 2;
    if(g[sz(g)-1][sz(g[0])-1] == 'A') return 2;
  }
  {
    // 3
    for(int i = 0; i < sz(g); i++) {
      for(int j = 0; j < sz(g[i]); j++) {
        bool side = i == 0 || i == sz(g)-1 || j == 0 || j == sz(g[i])-1;
        if(side && g[i][j] == 'A') return 3;
      }
    }
  }
  return ret;
}

vector<string> transpose(vector<string>& v) {
  vector<string> ret;
  for(int j = 0; j < sz(v[0]); j++) {
    string ans = "";
    for(int i = 0; i < sz(v); i++) {
      ans += v[i][j];
    }
    ret.push_back(ans);
  }
  return ret;
}

void rsolve() {
  int r, c;
  cin >> r >> c;
  vector<string> g(r);
  {
    bool ap = false;
    bool pp = false;
    for(int i = 0; i < r; i++) {
      cin >> g[i];
      for(int j = 0; j < c; j++) {
        ap |= g[i][j] == 'A';
        pp |= g[i][j] == 'P';
      }
    }
    if(!ap) {
      cout << "MORTAL\n";
      return;
    }
    if(!pp) {
      cout << "0\n";
      return;
    }
  }
  vector<string> gr = transpose(g);
  cout << min(solve(g), solve(gr)) << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}