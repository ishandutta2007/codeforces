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
typedef vector<string> matrix;

bool init[300005];
vector<pii> edges[100005];
int n, m;
vector<int> ret;

void dfs(int curr) {
  while(sz(edges[curr])) {
    pii out = edges[curr].back();
    edges[curr].pop_back();
    if(!init[out.second]) {
      init[out.second] = true;
      dfs(out.first);
      ret.push_back(curr);
    }
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back({b, i});
    edges[b].push_back({a, i});
  }
  vector<int> odd;
  for(int i = 1; i <= n; i++) {
    if(sz(edges[i])%2) odd.push_back(i);
  }
  assert(sz(odd)%2 == 0);
  for(int i = 0; i < sz(odd); i += 2) {
    edges[odd[i]].push_back({odd[i+1], m});
    edges[odd[i+1]].push_back({odd[i], m});
    m++;
  }
  if(m%2) {
    edges[1].push_back(pii(1, m));
    m++;
  }
  cerr << m << endl;
  for(int i = 1; i <= n; i++) {
    dfs(i);
  }
  cout << m << "\n";
  for(int i = 0; i < sz(ret); i++) {
    if(i%2) cout << ret[i] << " " << ret[(i+1)%sz(ret)] << "\n";
    else cout << ret[(i+1)%sz(ret)] << " " << ret[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}