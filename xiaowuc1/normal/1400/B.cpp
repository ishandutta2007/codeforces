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

void rsolve() {
  ll a, b;
  pii x, y; // <weight, cnt>
  cin >> a >> b >> x.s >> y.s >> x.f >> y.f;
  if(x.f > y.f) swap(x, y);
  int ret = 0;
  for(ll i = 0; i <= x.s; i++) {
    ll na = a - i * x.f;
    if(na < 0) break;
    pii xx = x;
    xx.s -= i;
    pii yy = y;
    ll nb = b;
    ll take = min(nb / xx.f, (ll)xx.s);
    nb -= take * xx.f;
    xx.s -= take;
    int cand = i + take;
    take = min(na / yy.f, (ll)yy.s);
    yy.s -= take; cand += take;
    take = min(nb / yy.f, (ll)yy.s);
    yy.s -= take; cand += take;
    ret = max(ret, cand);
  }
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
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