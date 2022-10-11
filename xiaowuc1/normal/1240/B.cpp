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
typedef pair<ll, ll> pll;
typedef long double ld;

int lis[300005];
void realsolve() {
  int n;
  cin >> n;
  map<int, pii> dp;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(!dp.count(x)) dp[x] = {i, i};
    else dp[x].second = i;
  }
  vector<pii> v;
  for(auto out: dp) {
    v.push_back(out.second);
  }
  int ret = 1;
  for(int i = 0; i < sz(v);) {
    int j = i+1;
    while(j < sz(v) && v[j].first > v[j-1].second) j++;
    ret = max(ret, j-i);
    i = j;
  }
  cout << sz(v) - ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}