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

int seen[1005];
int l[1005];
int id;
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  vector<int> ret;
  while(true) {
    /*
    for(int i = 0; i < n; i++) {
      cerr << l[i] << " ";
    } cerr << endl;
    */
    bool bad = false;
    for(int i = 1; i < n && !bad; i++) {
      bad = l[i] < l[i-1];
    }
    if(!bad) break;
    id++;
    for(int i = 0; i < n; i++) seen[l[i]] = id;
    int mex = 0;
    while(mex < n && seen[mex] == id) mex++;
    int cand = mex;
    if(cand == n) {
      int want = 0;
      while(true) {
        cand = 0;
        if(l[want] == want) {
          want++;
          continue;
        }
        else {
          while(l[cand] != want) cand++;
          l[cand] = mex;
          ret.push_back(cand+1);
          break;
        }
      }
      continue;
    }
    l[cand] = mex;
    ret.push_back(cand+1);
  }
  assert(sz(ret) <= 2*n);
  cout << sz(ret) << "\n";
  for(int i = 0; i < sz(ret); i++) {
    if(i) cout << " ";
    cout << ret[i];
  }
  cout << "\n";
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}