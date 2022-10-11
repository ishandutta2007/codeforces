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
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

ll l[3][100005];
int num[3];
int idx[3];
void rsolve() {
  cin >> num[0] >> num[1] >> num[2];
  memset(idx, 0, sizeof(idx));
  for(int k = 0; k < 3; k++) {
    for(int i = 0; i < num[k]; i++) cin >> l[k][i];
    sort(l[k], l[k] + num[k]);
  }
  ll ret = 4e18;
  while(idx[0] < num[0] && idx[1] < num[1] && idx[2] < num[2]) {
    for(int mask = 0; mask < 8; mask++) {
      vector<ll> v;
      for(int i = 0; i < 3; i++) {
        int realidx = idx[i];
        if(mask & (1<<i)) realidx++;
        if(realidx < num[i]) v.push_back(l[i][realidx]);
      }
      if(sz(v) != 3) continue;
      ll cand = 0;
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < i; j++) {
          cand += (v[i] - v[j]) * (v[i] - v[j]);
        }
      }
      ret = min(ret, cand);
    }
    priority_queue<pll> q;
    if(idx[0]+1 < num[0]) q.push({-l[0][idx[0]+1], 0});
    if(idx[1]+1 < num[1]) q.push({-l[1][idx[1]+1], 1});
    if(idx[2]+1 < num[2]) q.push({-l[2][idx[2]+1], 2});
    if(sz(q) == 0) break;
    idx[q.top().second]++;
  }
  cout << ret << "\n";
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