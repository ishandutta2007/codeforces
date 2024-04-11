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

int n, sx, sy;
int x[200000];
int y[200000];
int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};
void solve() {
  cin >> n >> sx >> sy;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int ret = -1;
  int ex = -1;
  int ey = -1;
  for(int k = 0; k < 4; k++) {
    int cx = sx + dx[k];
    int cy = sy + dy[k];
    if(min(cx, cy) < 0 || max(cx, cy) > 1e9) continue;
    int cand = 0;
    for(int i = 0; i < n; i++) {
      int d = abs(x[i] - sx) + abs(y[i] - sy);
      if(d == 1 + abs(x[i] - cx) + abs(y[i] - cy)) cand++;
    }
    if(cand > ret) {
      ret = cand;
      ex = cx;
      ey = cy;
    }
  }
  cout << ret << "\n";
  cout << ex << " " << ey << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}