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

const ll INF = 1LL << 40;

void solve() {
  int q;
  cin >> q;
  ll ret = 0;
  stack<ll> s;
  s.push(1LL);
  while(q--) {
    string op;
    cin >> op;
    if(op == "for") {
      int x;
      cin >> x;
      s.push(min(INF, x * s.top()));
    }
    else if(op == "add") {
      ret = min(INF, ret + s.top());
    }
    else {
      s.pop();
    }
  }
  if(ret >= 1LL << 32) cout << "OVERFLOW!!!\n";
  else cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}