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

void solve() {
  int n;
  cin >> n;
  ll a = 0;
  ll b = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x%2==0) {
      a += x/2;
      b += x/2;
      continue;
    }
    a += x/2;
    b += x/2;
    if(i%2==0) a++;
    else b++;
  }
  cout << min(a, b) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}