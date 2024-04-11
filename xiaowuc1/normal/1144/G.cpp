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

void die() {
  cout << "NO\n";
  exit(0);
}

int l[1000000];
bool ret[1000000];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  vector<int> inc, dec;
  inc.push_back(-2e9);
  dec.push_back(2e9);
  for(int i = 0; i < n; i++) {
    if(l[i] <= inc.back() && l[i] >= dec.back()) {
      die();
    }
    if(l[i] > inc.back() && l[i] >= dec.back()) {
      inc.push_back(l[i]);
      continue;
    }
    if(l[i] <= inc.back() && l[i] < dec.back()) {
      ret[i] = 1;
      dec.push_back(l[i]);
      continue;
    }
    assert(l[i] > inc.back() && l[i] < dec.back());
    if(i == n-1) {
      inc.push_back(l[i]);
      continue;
    }
    if(l[i+1] > l[i]) inc.push_back(l[i]);
    else {
      ret[i] = 1;
      dec.push_back(l[i]);
    }
  }
  cout << "YES\n";
  for(int i = 0; i < n; i++) {
    if(i) cout << " "; cout << (int)ret[i];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}