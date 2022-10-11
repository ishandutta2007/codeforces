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
typedef pair<pii, bool> piib;
typedef pair<double, double> pdd;
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;

ll vals[100005];
vector<int> edges[100005];
const int MOD = 1000000007;

int dfs(map<ll, int>& freq, int curr, int par = -1) {
  ll ret = 0;
  map<ll, int> realFreq;
  realFreq[vals[curr]]++;
  for(auto out: freq) {
    realFreq[__gcd(out.first, vals[curr])] += out.second;
  }
  // do it now
  for(auto out: realFreq) {
    ret += (out.first % MOD) * out.second;
    ret %= MOD;
  }
  for(int out: edges[curr]) {
    if(out == par) continue;
    ret += dfs(realFreq, out, curr);
    ret %= MOD;
  }
  return ret;
}
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> vals[i];
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  map<ll, int> dp;
  cout << dfs(dp, 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}