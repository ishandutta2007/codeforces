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

void die() {
  cout << "-1\n";
  exit(0);
}

int r, c;
string g[1005];
bool rowcovered[1005];
bool colcovered[1005];

int par[1000005];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return false;
  par[x] = y;
  return true;
}

void solve() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) cin >> g[i];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c;) {
      if(g[i][j] == '.') {
        j++;
        continue;
      }
      if(rowcovered[i]) die();
      rowcovered[i] = true;
      while(j < c && g[i][j] == '#') j++;
    }
  }
  for(int j = 0; j < c; j++) {
    for(int i = 0; i < r;) {
      if(g[i][j] == '.') {
        i++;
        continue;
      }
      if(colcovered[j]) die();
      colcovered[j] = true;
      while(i < r && g[i][j] == '#') i++;
    }
  }
  int nr = 0;
  int nc = 0;
  for(int i = 0; i < r; i++) nr += rowcovered[i];
  for(int j = 0; j < c; j++) nc += colcovered[j];
  if((nr == r) ^ (nc == c)) die();
  int ret = 0;
  for(int i = 0; i < r*c; i++) par[i] = i;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(g[i][j] == '.') continue;
      ret++;
      if(i+1 < r && g[i+1][j] == '#') ret -= merge(i*c+j, (i+1)*c+j);
      if(j+1 < c && g[i][j+1] == '#') ret -= merge(i*c+j, (i)*c+j+1);
    }
  }
  cout << ret << "\n";
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