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
#define derr if(0) cerr
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int loc[500000];
void solve() {
  map<int, int> dp;
  int ret = 0;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    dp[x] = i;
  }
  map<int, int> ans;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int want = dp[x] - i;
    if(want < 0) want += n;
    want %= n;
    ret = max(ret, ++ans[want]);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}