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

vector<int> edges[100005];
int sz[100005];
int n;

void dfs(int curr, int par, vector<ll>& v) {
  sz[curr] = 1;
  for(int out: edges[curr]) {
    if(out == par) continue;
    dfs(out, curr, v);
    ll gain = sz[out];
    gain *= (n - sz[out]);
    v.push_back(gain);
    sz[curr] += sz[out];
  }
}

const int MOD = 1000000007;

void rsolve() {
  cin >> n;
  for(int i = 1; i <= n; i++) edges[i].clear();
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int k;
  cin >> k;
  vector<int> p;
  for(int i = 0; i < k; i++) {
    int x;
    cin >> x;
    p.push_back(x);
  }
  vector<ll> contrib;
  sort(all(p));
  dfs(1, -1, contrib);
  sort(all(contrib));
  ll ret = 0;
  while(sz(contrib) || sz(p)) {
    ll inc = 1;
    while(sz(contrib) < sz(p)) {
      inc *= p.back();
      inc %= MOD;
      p.pop_back();
    }
    if(sz(p)) {
      inc *= p.back();
      inc %= MOD;
      p.pop_back();
    }
    inc *= contrib.back();
    inc %= MOD;
    contrib.pop_back();
    ret += inc;
    ret %= MOD;
  }
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