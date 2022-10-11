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
const int RAGETREE_SZ = 1 << 19;
const int RAGETREE_DEP = 17;
pii ragetree[RAGETREE_DEP][2 * RAGETREE_SZ];
void fix(int idx) {
  for(int i = RAGETREE_SZ-1; i > 0; i--) {
    ragetree[idx][i].first = min(ragetree[idx][2*i].first, ragetree[idx][2*i+1].first);
    ragetree[idx][i].second = max(ragetree[idx][2*i].second, ragetree[idx][2*i+1].second);
  }
}
pii qry(int idx, int lhs, int rhs) {
  assert(lhs <= rhs);
  pii ret = {2e9, 0};
  lhs += RAGETREE_SZ;
  rhs += RAGETREE_SZ;
  while(lhs <= rhs) {
    if(lhs == rhs) {
      ret.first = min(ret.first, ragetree[idx][lhs].first);
      ret.second = max(ret.second, ragetree[idx][lhs].second);
      break;
    }
    if(lhs%2) {
      ret.first = min(ret.first, ragetree[idx][lhs].first);
      ret.second = max(ret.second, ragetree[idx][lhs].second);
      lhs++;
    }
    if(rhs%2 == 0) {
      ret.first = min(ret.first, ragetree[idx][rhs].first);
      ret.second = max(ret.second, ragetree[idx][rhs].second);
      rhs--;
    }
    lhs /= 2;
    rhs /= 2;
  }
  return ret;
}

int l[300005];
int n;
void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    l[i+n] = l[i];
    l[i+2*n] = l[i];
  }
  n *= 3;
  for(int d = 0; d < RAGETREE_DEP; d++) for(int i = 0; i < RAGETREE_SZ; i++) ragetree[d][i+RAGETREE_SZ] = {2e9, 0};
  for(int i = 0; i < n; i++) {
    ragetree[0][i+RAGETREE_SZ] = {max(0, i - l[i]), min(n-1, i + l[i])};
  }
  for(int d = 1; d < RAGETREE_DEP; d++) {
    fix(d-1);
    for(int i = 0; i < n; i++) {
      ragetree[d][i + RAGETREE_SZ] = qry(d-1, ragetree[d-1][i+RAGETREE_SZ].first, ragetree[d-1][i+RAGETREE_SZ].second);
    }
  }
  fflush(stdout); cout << flush;
  fix(RAGETREE_DEP-1);
  n /= 3;
  for(int i = 0; i < n; i++) {
    int lhs = i+n;
    int rhs = i+n;
    int ret = 0;
    for(int d = RAGETREE_DEP-1; d > 0; d--) {
      pii q = qry(d, lhs, rhs);
      if(q.second - q.first + 1 < n) {
        ret += 1 << d;
        lhs = q.first;
        rhs = q.second;
      }
    }
    while(rhs-lhs+1 < n) {
      pii q = qry(0, lhs, rhs);
      ret++;
      lhs = q.first;
      rhs = q.second;
    }
    if(i) cout << " ";
    cout << ret;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}