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
typedef long double ld;

bool comp[1000005];
void solve() {
  for(int i = 2; i <= 1e3; i++) {
    for(int j = i*i; j <= 1e6; j+=i) {
      comp[j] = true;
    }
  }
  ll n;
  cin >> n;
  if(n == 1) {
    cout << "1\n";
    return;
  }
  ll ret = 2;
  bool isPrime = true;
  while(ret <= 1e6) {
    if(n%ret == 0) isPrime = false;
    if(comp[ret]) {
      ret++;
      continue;
    }
    ll cand = 1;
    while(cand < n) {
      cand *= ret;
    }
    if(cand == n) {
      cout << ret << "\n";
      return;
    }
    ret++;
  }
  if(isPrime) cout << n << "\n";
  else cout << 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}