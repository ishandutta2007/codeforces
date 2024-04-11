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

vector<int> edges[100005];

double dfs(int curr, int par = -1) {
  double nn = 0;
  ll dd = 0;
  for(int out: edges[curr]) {
    if(out == par) continue;
    dd++;
    nn += (1+dfs(out, curr));
  }
  if(dd == 0) return 0;
  return nn * 1.0 / dd;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  cout << fixed << setprecision(12) << dfs(1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}