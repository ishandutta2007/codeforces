#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  const ll mod = 998244353;

  int n; cin >> n;
  vector<ll> x(n), y(n), s(n);
  rep(i,0,n) cin >> x[i] >> y[i] >> s[i];
  vector<ll> prefCost(n+1);

// 0 1   2  3  4   5  6   7   8
// 0 x   x  |  x   x  |   |   |
//          4         8   13  27
  ll currCost = 0;
  rep(i,0,n) {
    ll distToWalk = x[i];
    if (i) distToWalk -= x[i-1];
    currCost += distToWalk;
    auto temp = lower_bound(all(x), y[i]);
    int numToLeft = temp - begin(x);

    // now let's walk to x[numToLeft-1]
    // we decrease this from our cost
    currCost -= y[i];
    if (numToLeft) currCost += x[numToLeft-1];

    // now let's calculate the cost of moving from numToLeft -> i
    // first move to i-1, then walk
    currCost += prefCost[i];
    currCost -= prefCost[numToLeft];
    currCost += distToWalk;
    currCost %= mod;
    if (currCost < 0) currCost += mod;
    prefCost[i+1] = currCost;
  }

  currCost = 0;
  rep(i,0,n) {
    ll distToWalk = x[i];
    if (i) distToWalk -= x[i-1];
    currCost += distToWalk;
    if (s[i]) {
      auto temp = lower_bound(all(x), y[i]);
      int numToLeft = temp - begin(x);

      // now let's walk to x[numToLeft-1]
      // we decrease this from our cost
      currCost -= y[i];
      if (numToLeft) currCost += x[numToLeft-1];

      // now let's calculate the cost of moving from numToLeft -> i
      // first move to i-1, then walk
      currCost += prefCost[i];
      currCost -= prefCost[numToLeft];
      currCost += distToWalk;
    }
    currCost %= mod;
    if (currCost < 0) currCost += mod;
  }
  currCost++;
  if(currCost == mod) currCost = 0;
  cout << currCost << endl;
}