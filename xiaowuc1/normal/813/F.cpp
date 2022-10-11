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

#include <unordered_map>

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

const int RAGETREE_SZ = 1 << 17;
int par[2 * RAGETREE_SZ];
vector<pii> ragetreelazy[2 * RAGETREE_SZ];
string ret[RAGETREE_SZ];
int n;

int find(int x) {
  while(par[x] != x) x = par[x]; return x;
}
bool apply(int idx, int lhs, int rhs, vector<pii>& historical) {
  // returns true if success
  lhs = find(lhs);
  rhs = find(rhs);
  if(lhs == rhs) return false;
  // do the merge, track historical state
  if(rand()&1) {
    historical.push_back({lhs, par[lhs]});
    par[lhs] = rhs;
  }
  else {
    historical.push_back({rhs, par[rhs]});
    par[rhs] = lhs;
  }
  return true;
}

void apply(int idx, int pos, int sz, int lhs, int rhs, int a, int b) {
  int rpos = pos + sz - 1;
  if(pos > rhs || rpos < lhs) return;
  if(pos >= lhs && rpos <= rhs) {
    ragetreelazy[idx].push_back({a, b});
    return;
  }
  apply(2*idx, pos, sz/2, lhs, rhs, a, b);
  apply(2*idx+1, pos + sz/2, sz/2, lhs, rhs, a, b);
}
void apply(int lhs, int rhs, int a, int b) {
  apply(1, 0, RAGETREE_SZ, lhs, rhs, a, b);
}
void prop(int idx, int pos, int sz) {
  vector<pii> old;
  bool done = false;
  while(sz(ragetreelazy[idx])) {
    pii curr = ragetreelazy[idx].back(); ragetreelazy[idx].pop_back();
    apply(idx, curr.first, curr.second + n, old);
    apply(idx, curr.first + n, curr.second, old);
    if(find(curr.first) == find(curr.first+n)) {
      done = true;
      for(int i = pos; i < pos+sz; i++) ret[i] = "NO";
      break;
    }
  }
  if(!done && sz > 1) {
    prop(2*idx, pos, sz/2);
    prop(2*idx+1, pos + sz/2, sz/2);
  }
  while(sz(old)) {
    pii key = old.back(); old.pop_back();
    par[key.first] = key.second;
  }
}
void prop() {
  prop(1, 0, RAGETREE_SZ);
}

typedef pair<pii, pii> event; // <lhs, rhs>, <mergea, mergeb>

bool eventsort(event a, event b) {
  return a.first.second-a.first.first > b.first.second-b.first.first;
}

void solve() {
  int q;
  cin >> n >> q;
  for(int i = 1; i <= 2*n; i++) par[i] = i;
  map<pii, int> dp;
  vector<event> events;
  for(int i = 0; i < q; i++) {
    ret[i] = "YES";
    pii key;
    cin >> key.first >> key.second;
    if(dp.count(key)) {
      events.push_back(event({dp[key], i-1}, key));
      dp.erase(key);
    }
    else {
      dp[key] = i;
    }
  }
  for(auto out: dp) {
    events.push_back(event({out.second, q-1}, out.first));
  }
  sort(all(events), eventsort);
  for(event out: events) {
    apply(out.first.first, out.first.second, out.second.first, out.second.second);
  }
  prop();
  for(int i = 0; i < q; i++) {
    cout << ret[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}