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
typedef pair<pii, int> query; // <radius, entrance>, idx
typedef long double ld;
typedef pair<double, pii> event; // distance, <a, b>

char g[15][15];

bool win() {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
          if(dx ==0 && dy == 0) break;
          bool good = true;
          for(int k = 0; k < 5; k++) {
            int nx = i + dx * k;
            int ny = j + dy * k;
            good &= nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && g[nx][ny] == 'X';
          }
          if(good) return true;
        }
      }
    }
  }
  return false;
}

void solve() {
  for(int i = 0; i < 10; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < 10; j++) {
      g[i][j] = s[j];
    }
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(g[i][j] != '.') continue;
      g[i][j] = 'X';
      if(win()) {
        cout << "YES\n";
        return;
      }
      g[i][j] = '.';
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}