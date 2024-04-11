#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<double>> matrix;

int a[105];
int b[105];
int c[105];
int r[105];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  r[0] = a[0];
  for(int i = 1; i < n; i++) {
    if(i == n-1) {
      if(a[i] != r[i-1] && a[i] != r[0]) r[i] = a[i];
      else if(b[i] != r[i-1]  && b[i] != r[0]) r[i] = b[i];
      else if(c[i] != r[i-1]  && c[i] != r[0]) r[i] = c[i];
      else assert(false);
    }
    else {
      if(a[i] != r[i-1]) r[i] = a[i];
      else if(b[i] != r[i-1]) r[i] = b[i];
      else if(c[i] != r[i-1]) r[i] = c[i];
      else assert(false);
    }
  }
  for(int i = 0; i < n; i++) cout << r[i] << " \n"[i == n-1];
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