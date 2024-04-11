#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<double>> matrix;

void upd(map<int, int>& m, int k, int v) {
  m[k] += v;
  if(m[k] == 0) m.erase(k);
}

vector<pii> events[1000050];
void solve() { 
  vector<pii> people, lights;
  int n, m;
  cin >> n >> m;
  people.resize(n);
  for(int i = 0; i < n; i++) cin >> people[i].f >> people[i].s;
  lights.resize(m);
  for(int i = 0; i < m; i++) cin >> lights[i].f >> lights[i].s;
  {
    sort(all(lights));
    vector<pii> nlights;
    for(auto out: lights) {
      while(sz(nlights) && nlights.back().s <= out.s) nlights.pop_back();
      nlights.pb(out);
    }
    lights.swap(nlights);
  }
  for(int i = 0; i < n; i++) {
    int lhst = 0;
    for(pii out: lights) {
      if(out.f < people[i].f) continue;
      if(out.s < people[i].s) break;
      int rhst = out.f - people[i].f;
      events[lhst].eb(out.s - people[i].s+1, 1);
      events[rhst+1].eb(out.s - people[i].s+1, -1);
      lhst = rhst+1;
    }
  }
  map<int, int> dp;
  int ret = 1e9;
  for(int x = 0; x <= 1000000; x++) {
    for(pii event: events[x]) {
      upd(dp, event.f, event.s);
    }
    int cand = x;
    if(sz(dp)) cand += dp.rbegin()->f;
    ret = min(ret, cand);
  }
  cout << ret << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}