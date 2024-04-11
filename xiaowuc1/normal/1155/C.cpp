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

ll l[300005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll gg = 0;
  for(int i = 1; i < n; i++) gg = __gcd(gg, l[i] - l[i-1]);
  for(int i = 1; i <= m; i++) {
    ll x;
    cin >> x;
    if(gg % x == 0) {
      cout << "YES\n";
      cout << l[0] << " " << i << "\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}