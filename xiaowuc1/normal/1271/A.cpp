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

void solve() {
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  ll ret = 0;
  if(e >= f) {
    ll x = min(a, d);
    ret += e * x;
    a -= x;
    d -= x;
  }
  else {
    ll x = min(min(b, c), d);
    ret += f * x;
    b -= x;
    c -= x;
    d -= x;
  }
  {
    ll x = min(a, d);
    ret += e * x;
    a -= x;
    d -= x;
  }
  {
    ll x = min(min(b, c), d);
    ret += f * x;
    b -= x;
    c -= x;
    d -= x;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}