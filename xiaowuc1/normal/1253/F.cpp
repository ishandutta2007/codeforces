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

int n, m, k, qq;
const int MAX_N = 100001;
vector<pii> allEdges[MAX_N];

typedef pair<ll, pii> mstedge;
vector<mstedge> mstedges;

set<int>* uf[MAX_N];
int lhsq[300005];
int rhsq[300005];
ll ret[300005];
map<pii, ll> retDP;
void queries() {
  sort(all(mstedges));
  for(int i = 1; i <= k; i++) {
    uf[i] = new set<int>;
    uf[i]->insert(i);
  }
  map<int, set<int>> dp;
  for(int i = 0; i < qq; i++) {
    cin >> lhsq[i] >> rhsq[i];
    ret[i] = 1e18;
    dp[lhsq[i]].insert(rhsq[i]);
    dp[rhsq[i]].insert(lhsq[i]);
  }
  for(auto edge: mstedges) {
    if(uf[edge.second.first] == uf[edge.second.second]) continue;
    set<int>* smaller = uf[edge.second.first];
    set<int>* larger = uf[edge.second.second];
    if(sz(*smaller) > sz(*larger)) swap(smaller, larger);
    for(int out: *smaller) {
      if(!dp.count(out)) continue;
      auto it = dp[out].begin();
      while(it != dp[out].end()) {
        if(larger->count(*it)) {
          pii key = {out, *it};
          if(!retDP.count(key)) retDP[key] = edge.first;
          key = {*it, out};
          if(!retDP.count(key)) retDP[key] = edge.first;
          dp[out].erase(it++);
        }
        else {
          it++;
        }
      }
      if(sz(dp[out]) == 0) dp.erase(out);
    }
    for(int out: *smaller) {
      larger->insert(out);
    }
    for(int out: *smaller) {
      uf[out] = larger;
    }
  }
  for(int i = 0; i < qq; i++) cout << retDP[{lhsq[i], rhsq[i]}] << "\n";
}

typedef pair<pll, int> vertex; // <<dist, source>, index>
pll dist[MAX_N];
bool added[MAX_N];

void mst() {
  for(int i = 1; i <= n; i++) dist[i] = {1e18, 1e18};
  dist[k] = {0, k};
  priority_queue<vertex> q;
  q.push(vertex({0, k}, k));
  added[k] = true;
  int adds = 0;
  while(adds < k-1 && sz(q)) {
    vertex curr = q.top(); q.pop();
    int currv = curr.second;
    int src = curr.first.second;
    if(dist[currv].first != -curr.first.first) continue;
    if(currv <= k && !added[currv]) {
      adds++;
      added[currv] = true;
      mstedges.push_back(mstedge(dist[currv].first, {currv, dist[currv].second}));
      dist[currv] = {0, currv};
      src = currv;
    }
    for(pii out: allEdges[currv]) {
      int nd = out.first;
      ll nw = out.second + dist[currv].first;
      if(pll(nw, src) < dist[nd]) {
        dist[nd] = {nw, src};
        q.push(vertex({-nw, src}, nd));
      }
    }
  }
  assert(adds == k-1);
}

void solve() {
  cin >> n >> m >> k >> qq;
  while(m--) {
    int a, b, w;
    cin >> a >> b >> w;
    allEdges[a].push_back({b, w});
    allEdges[b].push_back({a, w});
  }
  mst();
  queries();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}