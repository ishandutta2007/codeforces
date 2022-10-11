#include <algorithm>
#include <array>
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
typedef vector<vector<ll>> matrix;

int l[3500];
int n;
void rsolve() {
  int len, force;
  cin >> n >> len >> force;
  int use = n - len + 1;
  force = min(force, len-1);
  for(int i = 0; i < n; i++) cin >> l[i];
  int ret = 0;
  for(int start = 0; start <= force; start++) {
    int cand = 1e9;
    int canmove = len-force;
    for(int a = 0; a < canmove; a++) {
      cand = min(cand, max(l[start+a], l[start+a+use-1]));
    }
    ret = max(ret, cand);
  }
  cout << ret << "\n";
}
void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

// what would chika do
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