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

int cost[5005];
int discount[5005];
int par[5005];
int treesz[5005];
vector<int> children[5005];
int n;

// you must use coupons
ll dpuse[5005][5005];
// you can do whatever
ll dpnouse[5005][5005];

bool szsort(int a, int b) {
  return treesz[a] < treesz[b];
}

void dfs(int curr) {
  treesz[curr] = 1;
  for(int out: children[curr]) {
    dfs(out);
    treesz[curr] += treesz[out];
  }
  sort(all(children[curr]), szsort);
  dpuse[curr][0] = 0;
  dpnouse[curr][0] = 0;
  dpuse[curr][1] = cost[curr] - discount[curr];
  dpnouse[curr][1] = cost[curr];
  int mysz = 1;
  while(sz(children[curr]) > 0) { // TODO: zero case
    int child = children[curr].back(); children[curr].pop_back();
    mysz += treesz[child];
    for(int a = mysz; a > 0; a--) {
      for(int b = min(a, treesz[child]); b > 0; b--) {
        if(dpnouse[curr][a-b] > 1e14) break;
        if(a > b) dpuse[curr][a] = min(dpuse[curr][a], dpuse[curr][a-b] + dpuse[child][b]);
        dpnouse[curr][a] = min(dpnouse[curr][a], dpnouse[curr][a-b] + dpnouse[child][b]);
      }
    }
  }
  for(int a = 0; a <= mysz; a++) {
    dpuse[curr][a] = min(dpuse[curr][a], dpnouse[curr][a]);
  }
}

void solve() {
  int b;
  cin >> n >> b;
  memset(dpuse, 1, sizeof(dpuse));
  memset(dpnouse, 1, sizeof(dpnouse));
  for(int i = 1; i <= n; i++) {
    cin >> cost[i] >> discount[i];
    if(i > 1) {
      cin >> par[i];
      children[par[i]].push_back(i);
    }
  }
  dfs(1);
  int ret = 1;
  while(ret <= n && dpuse[1][ret] <= b) {
    ret++;
  }
  cout << --ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}