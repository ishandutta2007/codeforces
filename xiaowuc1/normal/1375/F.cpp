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
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

int readjudge() {
  int x;
  cin >> x;
  if(x == 0) exit(0);
  if(x == -1) exit(1);
  return x;
}

void cleanse(vector<pll>& v) {
  sort(all(v));
  for(int i = 2; i >= 0; i--) v[i].f -= v[0].f;
}

void solve() {
  vector<pll> v; // number of stones, original index
  for(int i = 1; i <= 3; i++) {
    ll x;
    cin >> x;
    v.emplace_back(x, i);
  }
  sort(all(v));
  cout << "First" << endl;
  int locked = -1;
  while(true) {
    cleanse(v);
    {
      // debug
      for(int i = 1; i <= 3; i++) {
        for(pll out: v) {
          if(out.s == i) cerr << out.f << " ";
        }
      }
      cerr << endl;
    }
    ll val = -1;
    // can we end the game
    if(v[2].s == locked && v[2].f - v[1].f == v[1].f - v[0].f) {
      // end the game
      val = v[2].f - v[1].f;
    }
    else if(v[1].s == locked) {
      // middle lock
      if(v[2].f < 2 * v[1].f) {
        // try to force right lock
        val = 2 * v[1].f - v[2].f;
      }
      else {
        // can't force lock, just force right anyway
        val = v[1].f;
      }
    }
    else if(v[2].s == locked) {
      // force leftmost
      if(rand() & 1) val = v[2].f - v[1].f;
      else val = v[2].f;
    }
    else {
      val = v[2].f - v[1].f;
    }
    cout << val << endl;
    locked = readjudge();
    for(int i = 0; i < 3; i++) {
      if(v[i].s == locked) v[i].f += val;
    }
  }
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}