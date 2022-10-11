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

#include <unordered_map>

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

void die() {
  cout << "NO\n";
  exit(0);
}

vector<int> children[2005];
int numsmaller[2005];
int n;
int root;
int ret[2005];
int treesz[2005];

void dfs(int curr, vector<int>& v) {
  if(treesz[curr] > sz(v)) die();
  if(numsmaller[curr] >= sz(v)) die();
  ret[curr] = v[numsmaller[curr]];
  v.erase(v.begin() + numsmaller[curr]);
  for(int out: children[curr]) {
    vector<int> take;
    if(treesz[out] > sz(v)) die();
    vector<int> now;
    while(sz(now) < treesz[out]) {
      now.push_back(v.back());
      v.pop_back();
    }
    reverse(all(now));
    dfs(out, now);
  }
}

void dfsforsz(int curr) {
  treesz[curr]++;
  for(int out: children[curr]) {
    dfsforsz(out);
    treesz[curr] += treesz[out];
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int p, x;
    cin >> p >> x;
    if(p == 0) root = i;
    else {
      children[p].push_back(i);
    }
    numsmaller[i] = x;
  }
  vector<int> p;
  for(int i = 1; i <= n; i++) p.push_back(i);
  dfsforsz(root);
  dfs(root, p);
  cout << "YES\n";
  for(int i = 1; i <= n; i++) {
    if(i > 1) cout << " ";
    cout << ret[i];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}