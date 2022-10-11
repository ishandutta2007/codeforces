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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int f(ull n) {
  int r = 0;
  while(n) {
    r += n%10;
    n /= 10;
  }
  return r;
}

void solve() {
  int t;
  cin >> t;
  while(t--) {
    ull orig;
    int k;
    cin >> orig >> k;
    ull n = orig;
    ull m = 10;
    while(f(n) > k) {
      while(n%m==0) m *= 10;
      n += (m - n%m);
    }
    cout << n-orig << "\n";
  }
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