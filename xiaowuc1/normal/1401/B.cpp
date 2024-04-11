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

int g[2][3];
ll ret = 0;
void take(int a, int b) {
  int x = min(g[0][a], g[1][b]);
  g[0][a] -= x;
  g[1][b] -= x;
  if(a > b) ret += (a)*(b)*x;
  else if(a < b) ret -= (a)*(b)*x;
}
void rsolve() {
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> g[i][j];
    }
  }
  ret = 0;
  take(2, 1);
  take(0, 2);
  take(2, 2);
  take(2, 0);
  take(1, 0);
  take(1, 1);
  take(1, 2);
  take(0, 0);
  take(0, 1);
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
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