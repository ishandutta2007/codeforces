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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

// NO SAD

const int BIT_SZ = 200010;
ll bit[BIT_SZ];
void upd(int idx, int val) {
  idx += 2;
  while(idx < BIT_SZ) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
ll qry(int idx) {
  idx += 2;
  ll ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

ll l[200005];
int ret[200005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    upd(i, i);
  }
  for(int i = 0; i < n; i++) cin >> l[i];
  set<int> all;
  for(int i = 0; i < n; i++) all.insert(i);
  for(int i = n-1; i >= 0; i--) {
    int lhs = *all.begin();
    int rhs = n-1;
    while(lhs != rhs) {
      int mid = (lhs+rhs)/2;
      if(qry(mid) >= l[i]) rhs = mid;
      else lhs = mid+1;
    }
    ret[i] = lhs+1;
    upd(lhs, -lhs);
    all.erase(lhs);
  }
  for(int i = 0; i < n; i++) {
    cout << ret[i];
    if(i == n-1) cout << "\n";
    else cout << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}