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
typedef pair<int, pii> state;

bool good[200005];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pii> v;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v.push_back({x, i});
  }
  sort(all(v));
  reverse(all(v));
  ll ret = 0;
  for(int i = 0; i < m*k; i++) {
    ret += v[i].first;
    good[v[i].second] = true;
  }
  // must have m
  cout << ret << "\n";
  int curr = 0;
  int amt = k;
  for(int i = 1; i <= n; i++) {
    if(good[i]) curr++;
    if(curr == m) {
      if(--amt) cout << i << " ";
      curr = 0;
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}