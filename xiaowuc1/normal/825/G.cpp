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

const int MAX_D = 20;
const int MAX_N = 1000001;
vector<int> edges[MAX_N];
int lca[MAX_N][MAX_D];
int lcamin[MAX_N][MAX_D];
int depth[MAX_N];
bool present[MAX_N];
int n;

int minRet;
int root;

int qry(int curr) {
  int ret = minRet;
  for(int d = MAX_D-1; d > 0; d--) {
    if(!present[lca[curr][d]]) {
      ret = min(ret, lcamin[curr][d]);
      curr = lca[curr][d];
    }
  }
  while(!present[curr]) {
    ret = min(ret, curr);
    curr = lca[curr][0];
  }
  return ret;
}

void add(int curr) {
  while(!present[curr]) {
    present[curr] = true;
    minRet = min(minRet, curr);
    curr = lca[curr][0];
  }
}

void init() {
  minRet = root;
  present[root] = true;
  memset(depth, 1, sizeof(depth));
  queue<int> q;
  q.push(root);
  depth[root] = 0;
  lca[root][0] = root;
  lcamin[root][0] = root;
  while(sz(q)) {
    int curr = q.front(); q.pop();
    for(int out: edges[curr]) {
      if(depth[out] > 1 + depth[curr]) {
        depth[out] = 1 + depth[curr];
        lca[out][0] = curr;
        lcamin[out][0] = out;
        q.push(out);
      }
    }
  }
  for(int d = 1; d < MAX_D; d++) {
    for(int i = 1; i <= n; i++) {
      lca[i][d] = lca[lca[i][d-1]][d-1];
      lcamin[i][d] = min(lcamin[i][d-1], lcamin[lca[i][d-1]][d-1]);
    }
  }
}
void solve() {
  int q;
  cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  q--;
  {
    int _;
    cin >> _ >> root;
    root = (root%n) + 1;
  }
  init();
  int last = 0;
  while(q--) {
    int t, x;
    cin >> t >> x;
    x = (x + last) % n + 1;
    if(t == 1) {
      add(x);
    }
    else {
      last = qry(x);
      cout << last << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}