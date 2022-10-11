#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(1) cerr
// END NO SAD

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

void solve() {
  int n;
  cin >> n;
  vector<ll> cap(n);
  for(int i = 0; i < n; i++) cin >> cap[i];
  ll tot = accumulate(all(cap), 0LL);
  vector<ll> need(n+1);
  {
    ll have = 0;
    ll maxsingle = 0;
    for(int i = 1; i <= n; i++) {
      have += cap[i-1];
      updmax(maxsingle, (have + i - 1) / i);
      need[i] = max(maxsingle, (tot + i - 1) / i);
    }
  }
  int q;
  cin >> q;
  while(q--) {
    ll amt;
    cin >> amt;
    int lhs = 1;
    int rhs = n;
    int ret = -1;
    while(lhs <= rhs) {
      int mid = (lhs+rhs)/2;
      if(need[mid] <= amt) {
        ret = mid;
        rhs = mid - 1;
      }
      else lhs = mid + 1;
    }
    cout << ret << "\n";
  }
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}