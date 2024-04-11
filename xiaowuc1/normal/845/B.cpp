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
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

bool is(int x) {
  int a = 0;
  for(int i = 0; i < 3; i++) {
    a += x%10; x /= 10;
  }
  int b = 0;
  for(int i = 0; i < 3; i++) {
    b += x%10; x /= 10;
  }
  return a == b;
}

int dist(int a, int b) {
  int ret = 0;
  for(int i = 0; i < 6; i++) {
    ret += a%10 != b%10;
    a /= 10;
    b /= 10;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  int ret = 100;
  for(int i = 0; i < 1000000; i++) if(is(i)) ret = min(ret, dist(n, i));
  cout << ret << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}