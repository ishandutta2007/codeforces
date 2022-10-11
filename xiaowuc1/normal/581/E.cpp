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

const int RAGETREE_SZ = 1 << 20;

int ragetree[2*RAGETREE_SZ][4]; // 0 is no fuel
int ragetreelazy[2*RAGETREE_SZ];

void apply(int idx, int id) {
  int tot = 0;
  for(int i = 0; i < 4; i++) tot += ragetree[idx][i];
  memset(ragetree[idx], 0, sizeof(ragetree[idx]));
  ragetree[idx][id] = tot;
  if(idx < RAGETREE_SZ){
    ragetreelazy[2*idx] = id;
    ragetreelazy[2*idx+1] = id;
  }
}
void pushdown(int idx) {
  if(ragetreelazy[idx]) {
    apply(2*idx, ragetreelazy[idx]);
    apply(2*idx+1, ragetreelazy[idx]);
    ragetreelazy[idx] = 0;
  }
}
void pullup(int idx) {
  for(int i = 0; i < 4; i++) ragetree[idx][i] = ragetree[2*idx][i] + ragetree[2*idx+1][i];
}

pii qry(int idx, int pos, int sz, int lhs, int rhs) {
  int rpos = pos + sz-1;
  if(rpos < lhs || pos > rhs) return {0, 0};
  if(pos >= lhs && rpos <= rhs) {
    if(ragetree[idx][0]) return {-1, -1};
    return {ragetree[idx][1], ragetree[idx][2]};
  }
  pushdown(idx);
  pii ans1 = qry(2*idx, pos, sz/2, lhs, rhs);

  pii ans2 = qry(2*idx+1, pos+sz/2, sz/2, lhs, rhs);
  pullup(idx);
  if(ans1.first < 0) return ans1;
  if(ans2.first < 0) return ans2;
  return {ans1.first + ans2.first, ans1.second + ans2.second};
}
pii qry(int lhs, int rhs) {
  return qry(1, 0, RAGETREE_SZ, lhs, rhs);
}

void upd(int idx, int pos, int sz, int lhs, int rhs, int id) {
  int rpos = pos + sz-1;
  if(rpos < lhs || pos > rhs) return;
  if(pos >= lhs && rpos <= rhs) {
    apply(idx, id);
    ragetreelazy[idx] = id;
    return;
  }
  pushdown(idx);
  upd(2*idx, pos, sz/2, lhs, rhs, id);
  upd(2*idx+1, pos+sz/2, sz/2, lhs, rhs, id);
  pullup(idx);
}
void upd(int lhs, int rhs, int id) {
  upd(1, 0, RAGETREE_SZ, lhs, rhs, id);
}

void init(int idx, int pos, int sz, vector<int>& v) {
  if(pos >= sz(v)) return;
  if(sz == 1) {
    ragetree[idx][0] = v[pos];
    return;
  }
  init(2*idx, pos, sz/2, v);
  init(2*idx+1, pos+sz/2, sz/2, v);
  pullup(idx);
}
void init(vector<int>& v) {
  init(1, 0, RAGETREE_SZ, v);
}

int qryi[200000];
int gasx[200001];
int gast[200001];

void solve() {
  int e, s, n, m; // dest, cap, gas, start
  cin >> e >> s >> n >> m;
  vector<int> interesting;
  for(int i = 0; i < n; i++) {
    cin >> gast[i] >> gasx[i];
    interesting.push_back(gasx[i]);
    interesting.push_back(gasx[i]+s);
  }
  interesting.push_back(e);
  for(int i = 0; i < m; i++) {
    cin >> qryi[i];
    interesting.push_back(qryi[i]+s);
  }
  sort(all(interesting));
  while(interesting.back() > e) interesting.pop_back();
  {
    vector<int> dists;
    for(int i = 1; i < sz(interesting); i++) dists.push_back(interesting[i] - interesting[i-1]);
    init(dists);
  }
  for(int x = 1; x <= 3; x++) {
    for(int i = 0; i < n; i++) {
      if(gast[i] != x) continue;
      int lhs = lower_bound(all(interesting), gasx[i]) - interesting.begin();
      int rhs = lower_bound(all(interesting), gasx[i]+s) - interesting.begin() - 1;
      upd(lhs, rhs, x);
    }
  }
  for(int i = 0; i < m; i++) {
    int lhs = lower_bound(all(interesting), qryi[i]+s) - interesting.begin();
    int rhs = lower_bound(all(interesting), e) - interesting.begin() - 1;
    pii ret = qry(lhs, rhs);
    cout << ret.first << " " << ret.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}