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
typedef pair<double, double> pdd;
typedef pair<pii, int> ppiii;
typedef bitset<1000005> bs;

void solve() {
  int n;
  cin >> n;
  vector<double> v;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  vector<int> ret;
  ll tot = 0;
  for(int i = 0; i < n; i++) {
    ret.push_back((int)floor(v[i]));
    tot += ret.back();
  }
  for(int i = 0; i < n && tot < 0; i++) {
    if(v[i] != ret[i]) {
      tot++;
      ret[i]++;
    }
  }
  assert(tot == 0);
  for(int out: ret) cout << out << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}