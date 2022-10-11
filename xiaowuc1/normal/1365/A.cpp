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
#define derr if(0) cerr
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void rsolve() {
  set<int> rs, cs;
  int r, c;
  cin >> r >> c;
  for(int i = 0; i < r; i++) rs.insert(i);
  for(int i = 0; i < c; i++) cs.insert(i);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int x;
      cin >> x;
      if(x == 1) {
        rs.erase(i);
        cs.erase(j);
      }
    }
  }
  int ret = min(sz(rs), sz(cs));
  if(ret%2 == 0) cout << "Vivek\n";
  else cout << "Ashish\n";
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