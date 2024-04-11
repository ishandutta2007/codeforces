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

void rsolve() {
  int n;
  cin >> n;
  vector<pii> v(n);
  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  sort(all(v));
  for(int i = 1; i < n; i++) {
    if(v[i].second < v[i-1].second) {
      cout << "NO\n";
      return;
    }
  }
  int a = 0;
  int b = 0;
  cout << "YES\n";
  for(pii out: v) {
    while(a < out.first) {
      a++;
      cout << "R";
    }
    while(b < out.second) {
      b++;
      cout << "U";
    }
  }
  cout << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}