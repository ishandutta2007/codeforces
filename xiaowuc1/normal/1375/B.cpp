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
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

int g[305][305];
int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};
void rsolve() {
  int r, c;
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> g[i][j];
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int amt = 0;
      for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        amt++;
      }
      if(amt < g[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int amt = 0;
      for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        amt++;
      }
      cout << amt << " \n"[j == c-1];
    }
  }
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}