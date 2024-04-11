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
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;

bool prime(int x) {
  if(x <= 1) return false;
  for(int i = 2; i * i <= x; i++) {
    if(x%i==0) return false;
  }
  return true;
}

void solveFast(int n) {
  set<int> seen;
  int m = n;
  vector<pii> add;
  int inc = 0;
  while(!prime(m)) {
    int lhs = 0;
    while(seen.count(lhs)) lhs++;
    int rhs = lhs+2;
    while(seen.count(rhs)) {
      rhs++;
      rhs %= n;
    }
    assert(rhs+1 != lhs && rhs != lhs);
    m++;
    inc++;
    add.push_back({lhs, rhs});
    seen.insert(lhs);
    seen.insert(rhs);
  }
  assert(prime(m));
  cout << m << "\n";
  for(pii out: add) {
    cout << out.first+1 << " " << out.second+1 << "\n";
  }
  for(int i = 1; i <= n; i++) {
    cout << i << " ";
    if(i == n) cout << 1;
    else cout << i+1;
    cout << "\n";
  }
}

void solve() {
  int n;
  cin >> n;
  solveFast(n);
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