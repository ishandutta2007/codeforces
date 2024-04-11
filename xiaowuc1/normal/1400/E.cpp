#include <algorithm>
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
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int l[5005];
int solve(int lhs, int rhs) {
  if(lhs == rhs) {
    return l[lhs] > 0 ? 1 : 0;
  }
  int minv = 1e9;
  int dist = 0;
  for(int i = lhs; i <= rhs; i++) {
    if(l[i] == 0) {
      minv = 0;
    }
    else {
      minv = min(minv, l[i]);
      dist++;
    }
  }
  for(int x = lhs; x <= rhs; x++) l[x] -= minv;
  int ret = minv;
  for(int i = lhs; i <= rhs;) {
    if(l[i] == 0) {
      i++;
      continue;
    }
    int j = i+1;
    while(j <= rhs && l[j]) j++;
    ret += solve(i, j-1);
    i = j;
  }
  return min(dist, ret);
}
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  cout << solve(0, n-1) << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}