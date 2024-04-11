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

typedef pair<pii, int> state;
int treesz[1000000];
int treedepth[1000000];
vector<int> edges[1000000];
bool marked[1000000];
int parent[1000000];
ll dfsforans(int curr, int par, int amt) {
  ll ret = 0;
  if(!marked[curr]) ret += amt;
  for(int out: edges[curr]) {
    if(out == par) continue;
    ret += dfsforans(out, curr, amt + marked[out]);
  }
  return ret;
}
void dfs(int curr, int par) {
  for(int out: edges[curr]) {
    if(out == par) continue;
    parent[out] = curr;
    treedepth[out] = treedepth[curr] + 1;
    dfs(out, curr);
    treesz[curr] += treesz[out];
  }
  treesz[curr]++;
}
void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfs(1, -1);
  vector<pii> v;
  for(int i = 1; i <= n; i++) v.emplace_back(treedepth[i] - treesz[i], i);
  sort(all(v));
  for(int i = 0; i < n-k; i++) marked[v[i].second] = true;
  cout << dfsforans(1, -1, marked[1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}