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
  ll n, k, m;
  cin >> n >> k >> m;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(all(v));
  ll totSum = 0;
  for(ll out: v) totSum += out;
  double ret = (totSum + min(m, k*n)) / (double)n;
  for(int i = 0; i < n-1 && i < m; i++) {
    totSum -= v[i];
    ret = max(ret, (totSum + min((m-i-1), k*(n-i-1))) / double(n-1-i));
  }
  cout << fixed << setprecision(12) << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}