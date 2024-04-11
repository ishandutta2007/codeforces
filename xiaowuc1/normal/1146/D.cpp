#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int minH[100005];
// what is the minimum height needed to get to minA[100005]

ll lowestMult(ll x, ll a, ll m) {
  // what is the lowest value y > x such that y \equiv a mod m
  ll y = x - (x%m);
  y += a;
  while(y <= x) y += m;
  return y;
}

// (x) + (x-d) + ..., k terms
ll arithSum(ll x, ll d) {
  ll k = (x/d)+1;
  return k*x - (k*(k-1)/2) * d;
}

void solve() {
  int m, a, b;
  cin >> m >> a >> b;
  for(int i = 0; i < a; i++) {
    minH[i] = (m+1);
  }
  int rhs = 0;
  int maxH = 0;
  minH[0] = 0;
  while(true) {
    rhs += a;
    if(rhs > m) break;
    maxH = max(maxH, rhs);
    bool bad = false;
    for(int i = rhs; i >= 0 && !bad; i -= b) {
      if(i < a) {
        // cout << "compare " << i << " and " << maxH << " against " << minH[i] << endl;
        if(minH[i] > maxH) {
          minH[i] = maxH;
        }
        else {
          bad = true;
        }
      }
    }
    if(bad) break;
    rhs %= b;
  }
  ll ret = 0;
  for(int i = 0; i < a; i++) {
    if(minH[i] > m) continue;
    ll numBound = (minH[i] - i) / a + 1;
    // cout << i << " needs min height of " << minH[i] << endl;
    // cout << i << " has num bound " << numBound << endl;
    // cout << "accumulate " << (m - minH[i] + 1) << endl;
    ret += numBound * (m - minH[i] + 1);
    ll nextD = lowestMult(minH[i], i, a);
    if(nextD <= m) {
      ll init = m - (nextD) + 1;
      ll drop = a;
      ret += arithSum(init, drop);
    }
    // cout << i << ": " << ret << endl;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}