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
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int rt, bt;
int rc[1000000];
int bc[1000000];
int n;
int color[1000000];
int pp[1000000];
vector<int> edges[1000000];
void dfs(int curr, int par = -1) {
  pp[curr] = par;
  for(int out: edges[curr]) {
    if(out == par) continue;
    dfs(out, curr);
    rc[curr] += rc[out];
    bc[curr] += bc[out];
  }
  if(color[curr] == 1) rc[curr]++;
  if(color[curr] == 2) bc[curr]++;
}
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> color[i];
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    if(color[i] == 1) rt++;
    if(color[i] == 2) bt++;
  }
  dfs(1);
  int ret = 0;
  for(int i = 2; i <= n; i++) {
    if(rc[i] && bc[i]) continue;
    if(rt-rc[i] && bt-bc[i]) continue;
    ret++;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}