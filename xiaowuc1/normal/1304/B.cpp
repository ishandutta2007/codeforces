#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#include <unordered_map>
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
#define derr if(0) cerr
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
  int n, k;
  cin >> n >> k;
  multiset<string> cands;
  while(n--) {
    string s;
    cin >> s;
    cands.insert(s);
  }
  string middle = "";
  string lhs = "";
  string rhs = "";
  auto ispalin = [&](const string& ss) -> bool {
    string tt = ss;
    reverse(all(tt));
    return ss == tt;
  };
  while(sz(cands)) {
    string curr = *cands.begin();
    cands.erase(cands.begin());
    if(ispalin(curr)) {
      middle = curr;
    }
    else {
      string go = curr;
      reverse(all(go));
      auto it = cands.find(go);
      if(it != cands.end()) {
        lhs += curr;
        rhs = go + rhs;
        cands.erase(it);
      }
    }
  }
  cout << sz(lhs)+sz(middle)+sz(rhs) << "\n";
  cout << lhs << middle << rhs << "\n";
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}