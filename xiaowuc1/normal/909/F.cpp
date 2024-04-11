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

#include <unordered_map>

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
typedef pair<pii, pii> state;

const int MOD = 1000000007;

int pos[1 << 18];
void constructzero(int n) {
  if(n%2) {
    cout << "NO\n";
    return;
  }
  vector<int> ret(n);
  for(int i = 1; i <= n; i++) {
    pos[i] = i-1;
  }
  while(n > 0) {
    int x = 1 << 20;
    while(x > n) x /= 2;
    int lhs = x-1;
    int rhs = x;
    while(rhs <= n) {
      swap(pos[lhs--], pos[rhs++]);
    }
    n = lhs;
  }
  for(int i = 1; i <= sz(ret); i++) {
    ret[pos[i]] = i;
  }
  cout << "YES\n";
  for(int i = 0; i < sz(ret); i++) {
    if(i) cout << " "; cout << ret[i];
  } cout << "\n";
}

void constructone(int n) {
  if(n < 6 || (n&(n-1)) == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if(n == 6) {
    cout << "5 3 1 6 4 2\n";
    return;
  }
  if(n == 7) {
    cout << "5 3 1 7 6 4 2\n";
    return;
  }
  cout << "5 3 1 7 6 4 2";
  for(int x = 8; x <= n; x *= 2) {
    vector<int> y;
    for(int z = x; z <= n && z < 2*x; z++) y.push_back(z);
    y.push_back(y[0]);
    y.erase(y.begin());
    for(int out: y) cout << " " << out;
  } cout << "\n";
}

void solve() {
  int n;
  cin >> n;
  constructzero(n);
  constructone(n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}