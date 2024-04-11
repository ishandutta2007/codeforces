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

const int MAX_N = 1000005;
vector<int> verticesatdist[MAX_N];
vector<int> edgesr[MAX_N];
int par[MAX_N];
int dp[MAX_N];

void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    edgesr[b].push_back(a);
    par[a]++;
  }
  int s, t;
  cin >> s >> t;
  memset(dp, 1, sizeof(dp));
  dp[t] = 0;
  verticesatdist[0].push_back(t);
  int ret = 0;
  while(sz(verticesatdist[ret]) && dp[s] > MAX_N) {
    for(int i = 0; i < sz(verticesatdist[ret]); i++) {
      int curr = verticesatdist[ret][i];
      for(int out: edgesr[curr]) {
        if(--par[out] == 0) {
          if(dp[out] > ret) {
            dp[out] = ret;
            verticesatdist[ret].push_back(out);
          }
        }
      }
    }
    for(int i = 0; i < sz(verticesatdist[ret]); i++) {
      int curr = verticesatdist[ret][i];
      for(int out: edgesr[curr]) {
        if(dp[out] > dp[curr] + 1) {
          dp[out] = dp[curr] + 1;
          verticesatdist[ret+1].push_back(out);
        }
      }
    }
    ret++;
  }
  if(dp[s] > MAX_N) cout << "-1\n";
  else cout << dp[s] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}