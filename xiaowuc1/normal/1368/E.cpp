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
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void usacoio(string s) {
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout);
}

vector<int> edges[200005];
int dp[200005];
bool bad[200005];
void rsolve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    dp[i] = 0;
  }
  for(int i = 1; i <= n; i++) {
    edges[i].clear();
  }
  for(int i = 1; i <= n; i++) {
    bad[i] = false;
  }
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }
  for(int i = 1; i <= n; i++) {
    if(bad[i]) continue;
    for(int out: edges[i]) {
      if(dp[i] == 1) {
        bad[out] = true;
      }
      else {
        assert(dp[i] == 0);
        dp[out] = 1;
      }
    }
  }
  vector<int> ret;
  for(int i = 1; i <= n; i++) if(bad[i]) ret.push_back(i);
  cout << sz(ret) << "\n";
  for(int i = 0; i < sz(ret); i++) {
    if(i) cout << " ";
    cout << ret[i];
  }
  cout << "\n";
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