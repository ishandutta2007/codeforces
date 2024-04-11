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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;

void realsolve() {
  int n;
  cin >> n;
  priority_queue<int> q;
  while(n--) {
    int t;
    cin >> t;
    q.push(-t);
  }
  while(!q.empty()) {
    int curr = -q.top(); q.pop();
    if(curr == 2048) {
      cout << "YES\n";
      return;
    }
    if(curr > 2048) {
      cout << "NO\n";
      return;
    }
    if(q.size() && -q.top() == curr) {
      curr *= 2;
      q.pop();
      q.push(-curr);
    }
  }
  cout << "NO\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}