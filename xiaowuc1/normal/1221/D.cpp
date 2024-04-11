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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;

void realsolve() {
  int n;
  cin >> n;
  map<int, ll> dp;
  dp[-5] = 0;
  while(n--) {
    map<int, ll> ndp;
    int a, b;
    cin >> a >> b;
    for(int x = a; x <= a+2; x++) {
      ll inc = (x-a) * (ll)b;
      for(auto out: dp) {
        if(out.first != x) {
          if(!ndp.count(x)) ndp[x] = out.second + inc;
          else ndp[x] = min(ndp[x], out.second + inc);
        }
      }
    }
    dp = ndp;
  }
  ll ret = 1e18;
  for(auto out: dp) ret = min(ret, out.second);
  cout << ret << "\n";
}

void solve() {
  int n;
  cin >> n;
  while(n--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}