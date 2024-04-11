#include <algorithm>
#include <array>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

int fa[200005];
int la[200005];
void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  {
    int idx = 0;
    for(int i = 0; i < m; i++) {
      while(s[idx] != t[i]) idx++;
      fa[i] = idx++;
    }
  }
  {
    int idx = sz(s)-1;
    for(int i = m-1; i >= 0; i--) {
      while(s[idx] != t[i]) idx--;
      la[i] = idx--;
    }
  }
  int ret = 1;
  for(int i = 0; i + 1 < m; i++) ret = max(ret, la[i+1] - fa[i]);
  cout << ret << "\n";
}

// !editcommand?
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}