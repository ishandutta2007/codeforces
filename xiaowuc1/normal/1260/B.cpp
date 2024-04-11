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

void rsolve() {
  ll a, b;
  cin >> a >> b;
  if((a+b)%3) {
    cout << "NO\n";
    return;
  }
  if(2*a < b) {
    cout << "NO\n";
    return;
  }
  if(2*b < a) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) {
    rsolve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}