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

int l[300005];
ll hashes[300005];
ll pref[300005];
mt19937 g1;
ll ret = 0;
int n;
ll want[300005];

int seen[300005];
int idx;
void solve(int start) {
  seen[1] = ++idx;
  int rhs = 1;
  for(int i = start+1; i < n; i++) {
    if(seen[l[i]] == idx) return;
    seen[l[i]] = idx;
    rhs = max(rhs, l[i]);
    int lhs = i - rhs + 1;
    if(lhs >= 0 && (pref[i+1] ^ pref[lhs]) == want[rhs]) {
      ret++;
    }
  }
}

void solve() {
  g1.seed(std::chrono::system_clock::now().time_since_epoch().count());
  cin >> n;
  for(int i = 1; i <= n; i++) {
    hashes[i] = uniform_int_distribution<ll>()(g1);
    want[i] = want[i-1] ^ hashes[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    pref[i+1] = pref[i] ^ hashes[l[i]];
  }
  for(int i = 0; i < n; i++) if(l[i] == 1) ret++;
  for(int i = 0; i < n; i++) {
    if(l[i] == 1) solve(i);
  }
  cerr << ret << endl;
  reverse(l, l+n);
  for(int i = 0; i < n; i++) {
    pref[i+1] = pref[i] ^ hashes[l[i]];
  }
  for(int i = 0; i < n; i++) {
    if(l[i] == 1) solve(i);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}