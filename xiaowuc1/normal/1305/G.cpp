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
 
const int MAX_N = 200005;
const int MAX_V = 1 << 18;
int l[MAX_N];
int n;
int par[MAX_V];
int sz[MAX_V];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
ll merge(int x, int y) {
  ll ret = sz[x] + (ll)sz[y] - 1;
  int ox = x;
  int oy = y;
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  sz[ox] = 1;
  sz[oy] = 1;
  if(rand() & 1) par[x] = y;
  else par[y] = x;
  return ret;
}
void solve() {
  cin >> n;
  sz[0]++;
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    sz[l[i]]++;
  }
  for(int i = 1; i < MAX_V; i++) par[i] = i;
  ll ret = 0;
  for(int i = MAX_V-1; i > 0; i--) {
    int mask = (MAX_V-1) & i;
    while(mask > 0) {
      int othermask = mask ^ i;
      if(othermask > mask) break;
      if(sz[mask] && sz[othermask]) {
        ret += merge(mask, othermask) * i;
      }
      mask = (mask-1) & i;
    }
  }
  for(int i = 1; i <= n; i++) ret -= l[i];
  cout << ret << "\n";
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}