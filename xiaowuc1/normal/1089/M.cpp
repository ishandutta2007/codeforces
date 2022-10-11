#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define derr if(1) cerr
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<int, pii> state;

char ret[3][27][27];
void solve() {
  int n;
  cin >> n;
  memset(ret, '#', sizeof(ret));
  // vertical tunnels
  for(int j = 0; j < 3*n; j += 3) {
    for(int i = 0; i < 3*n; i++) {
      ret[2][i][j] = '.';
      ret[2][i][j+1] = '.';
    }
    // staircase
    ret[2][j][j] = (char)('1' + j/3);
    ret[2][j+1][j] = '#';
    ret[1][j][j] = '.';
    ret[1][j+1][j] = '.';
    ret[0][j+1][j] = '.';
    ret[0][j+2][j] = '.';
    for(int col = 0; col < 3*n; col++) {
      ret[0][j+2][col] = '.';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if(x) {
        ret[0][3*i+1][3*j+1] = '.';
        ret[1][3*i+1][3*j+1] = '.';
      }
    }
  }
  cout << (3*n) << " " << (3*n) << " " << 3 << "\n";
  for(int z = 0; z < 3; z++) {
    if(z) cout << "\n";
    for(int i = 0; i < 3*n; i++) {
      for(int j = 0; j < 3*n; j++) {
        cout << ret[z][i][j];
      }
      cout << "\n";
    }
  }
}
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}