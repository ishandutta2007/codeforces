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

void solve() {
  ll maxV;
  int numItems;
  ll pageSz;
  cin >> maxV >> numItems >> pageSz;
  vector<ll> v;
  for(int i = 0; i < numItems; i++) {
    ll t;
    cin >> t;
    v.push_back(--t);
  }
  reverse(v.begin(), v.end());
  int ret = 0;
  int numDeleted = 0;
  while(v.size()) {
    int inc = 0;
    ll actualPage = (v.back() - numDeleted) / pageSz;
    while(v.size() && (v.back() - numDeleted) / pageSz == actualPage) {
      v.pop_back();
      inc++;
    }
    ret++;
    numDeleted += inc;
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