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

typedef pair<int, ll> pill;

vector<int> allV;
class medianBIT {
  vector<ll> sumbit;
  vector<int> cntbit;
  map<int, int> lower;
  int lowersize;
  map<int, int> greater;
  int greatersize;
  ll totalSum;
  public:
  ll query() {
    if(totalSum == 0) return 0;
    int med = greater.begin()->first;
    int idx = lower_bound(allV.begin(), allV.end(), med) - allV.begin();
    pill x = _bit_query(idx);
    ll rhssum = totalSum - x.second;
    int rhsamt = greatersize + lowersize - x.first;
    ll ans = (med * (ll)x.first - x.second) + (rhssum - med * (ll)rhsamt);
    return ans;
  }
  void _rebalance() {
    while(greatersize - lowersize > 1) {
      int merge = greater.begin()->first;
      lower[merge]++;
      lowersize++;
      if(--greater[merge] == 0) greater.erase(merge);
      greatersize--;
    }
    while(lowersize > greatersize) {
      int merge = lower.rbegin()->first;
      if(--lower[merge] == 0) lower.erase(merge);
      lowersize--;
      greater[merge]++;
      greatersize++;
    }
    if(lowersize == 0) return;
    while(lower.rbegin()->first > greater.begin()->first) {
      int lowup = lower.rbegin()->first;
      int highdown = greater.begin()->first;
      if(--lower[lowup] == 0) lower.erase(lowup);
      greater[lowup]++;
      if(--greater[highdown] == 0) greater.erase(highdown);
      lower[highdown]++;
    }
  }
  medianBIT() {
    sumbit.resize(allV.size() + 2);
    cntbit.resize(allV.size() + 2);
    lower.clear();
    lowersize = 0;
    greater.clear();
    greatersize = 0;
    totalSum = 0;
  }
  void _bit_update(int idx, int val) {
    totalSum += val;
    idx++;
    while(idx < sumbit.size()) {
      sumbit[idx] += val;
      if(val >= 0) cntbit[idx]++;
      else cntbit[idx]--;
      idx += idx & -idx;
    }
  }
  pill _bit_query(int idx) {
    idx++;
    ll sumret = 0;
    int cntret = 0;
    while(idx) {
      sumret += sumbit[idx];
      cntret += cntbit[idx];
      idx -= idx & -idx;
    }
    return {cntret, sumret};
  }
  void insert(int v) {
    if(lowersize == greatersize) {
      greatersize++;
      greater[v]++;
    }
    else {
      lowersize++;
      lower[v]++;
    }
    int idx = lower_bound(allV.begin(), allV.end(), v) - allV.begin();
    _bit_update(idx, v);
    _rebalance();
  }
};

const int BIT_SZ = 1 << 18;
int bit[BIT_SZ];
void upd(int idx, int val) {
  idx++;
  while(idx < BIT_SZ) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int qry(int idx) {
  idx++;
  int ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int l[200005];
int pos[200005];
ll ret[200005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) allV.push_back(i);
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    pos[--l[i]] = i;
  }
  {
    ll curr = 0;
    for(int i = 0; i < n; i++) {
      curr += i - qry(pos[i]);
      upd(pos[i], 1);
      ret[i] += curr;
    }
  }
  {
    medianBIT mbit;
    for(int i = 0; i < n; i++) {
      mbit.insert(pos[i]);
      ll inc = mbit.query();
      int rhs = i/2;
      int lhs = (i-rhs);
      inc -= (lhs * (lhs+1LL)) / 2;
      inc -= (rhs * (rhs+1LL)) / 2;
      ret[i] += inc;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i) cout << " "; cout << ret[i];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}