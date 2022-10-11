#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
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
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

const int SZ = 1 << 18;
int tamt[2*SZ];
ll tsum[2*SZ];
void upd(int idx, int delta) {
  idx += SZ;
  while(idx > 0) {
    if(delta > 0) tamt[idx]++; else tamt[idx]--;
    assert(tamt[idx] >= 0);
    tsum[idx] += delta;
    idx /= 2;
  }
}
ll qry(int k) {
  // return the sum of the top k
  int idx = 1;
  ll ret = 0;
  while(idx < SZ) {
    if(tamt[2*idx+1] <= k) {
      ret += tsum[2*idx+1];
      k -= tamt[2*idx+1];
      idx = 2*idx;
    }
    else {
      idx = 2*idx+1;
    }
  }
  if(tamt[idx] <= k) ret += tsum[idx];
  return ret;
}
pii l[200000];
int n;

void upd(map<int, int>& m, int k, int v) {
  m[k] += v;
  if(m[k] == 0) m.erase(k);
}

void solve() {
  cin >> n;
  vector<int> allv;
  for(int i = 0; i < n; i++) {
    cin >> l[i].f >> l[i].s;
    if(l[i].s > 0) allv.push_back(l[i].s);
  }
  sort(all(allv));
  allv.resize(unique(all(allv)) - allv.begin());
  map<int, int> fire, lightning;
  fire[0]++; // 
  int lamt = 0;
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(all(allv), abs(l[i].s)) - allv.begin();
    upd(idx, l[i].s);
    if(l[i].f == 0) {
      if(l[i].s > 0) upd(fire, l[i].s, 1);
      else upd(fire, -l[i].s, -1);
    }
    else {
      if(l[i].s > 0) {
        upd(lightning, l[i].s, 1);
        lamt++;
      }
      else {
        upd(lightning, -l[i].s, -1);
        lamt--;
      }
    }
    ll ret = tsum[1] + qry(lamt);
    if(lamt == 0) {
      cout << ret << "\n";
      continue;
    }
    // the doubling is incorrect iff the largest fire is < the smallest lightning?
    // if incorrect, throw away the smallest lightning, replace with the largest fire
    if(fire.rbegin()->first < lightning.begin()->first) {
      ret -= lightning.begin()->first;
      ret += fire.rbegin()->first;
    }
    cout << ret << "\n";
  }
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