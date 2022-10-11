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

ll parYes[500005]; // parent edge was colored
ll parNo[500005]; // parent edge was not colored
vector<pii> edges[500005];
int n, k;

bool pllcomp(pll a, pll b) {
  return a.first - a.second > b.first - b.second;
}

ll solve(int curr, int par, int flag) {
  if(flag == 0 && parNo[curr] >= 0) return parNo[curr];
  if(flag == 1 && parYes[curr] >= 0) return parYes[curr];
  ll ret = 0;
  vector<pll> choices;
  for(pii out: edges[curr]) {
    if(out.first == par) continue;
    ll didColor = out.second + solve(out.first, curr, 1);
    ll didNot = solve(out.first, curr, 0);
    choices.push_back({didColor, didNot});
  }
  int canColor = min(k - flag, sz(choices));
  nth_element(choices.begin(), choices.begin() + canColor, choices.end(), pllcomp);
  for(int i = 0; i < sz(choices); i++) {
    if(i < canColor) {
      ret += max(choices[i].first, choices[i].second);
    }
    else {
      ret += choices[i].second;
    }
  }
  if(flag == 0) parNo[curr] = ret;
  else parYes[curr] = ret;
  return ret;
}

void realsolve() {
  cin >> n >> k;
  for(int i = 1; i < n; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }
  for(int i = 1; i <= n; i++) {
    parYes[i] = -1;
    parNo[i] = -1;
  }
  cout << solve(1, -1, 0) << "\n";
  for(int i = 1; i <= n; i++) {
    edges[i].clear();
  }
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