#include <algorithm>
#include <bitset>
#include <cassert>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> query;

const int BIT_SZ = 200010;
int bit[BIT_SZ];
void upd(int idx) {
  idx += 2;
  while(idx < BIT_SZ) {
    bit[idx]++;
    idx += idx & -idx;
  }
}
int qry(int idx) {
  idx += 2;
  int ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

bool yDown(pii a, pii b) {
  return a.second > b.second;
}

bool xPresent[200005];
inline ll chooseTwo(ll n) {
  // you have N options, how many distinct can you pick
  if(n <= 0) return 0;
  return (n*(n+1))/2;
}
void solve() {
  int n;
  vector<pii> v;
  vector<int> xs;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    xs.push_back(x);
    v.emplace_back(x, y);
  }
  sort(xs.begin(), xs.end());
  sort(v.begin(), v.end(), yDown);
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(xs.begin(), xs.end(), v[i].first) - xs.begin();
    v[i].first = idx;
  }
  int numPresent = 0;
  ll ret = 0;
  for(int i = 0; i < n;) {
    int j = i;
    vector<int> allxs;
    while(j < n && v[i].second == v[j].second) {
      allxs.push_back(v[j].first);
      if(!xPresent[v[j].first]) {
        xPresent[v[j].first] = true;
        upd(v[j].first);
        numPresent++;
      }
      j++;
    }
    sort(allxs.begin(), allxs.end());
    ret -= chooseTwo(qry(allxs[0]-1));
    ret -= chooseTwo(numPresent - qry(allxs.back()));
    for(int k = 1; k < allxs.size(); k++) {
      if(allxs[k] != allxs[k-1]) ret -= chooseTwo(qry(allxs[k]-1) - qry(allxs[k-1]));
    }
    ret += chooseTwo(numPresent);
    i = j;
  }
  cout << ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}