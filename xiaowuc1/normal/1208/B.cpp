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

int l[2005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int ret = n;
  for(int lhs = 0; lhs <= n; lhs++) {
    set<int> s;
    for(int i = 0; i < lhs; i++) {
      s.insert(l[i]);
    }
    if(s.size()  != lhs) break;
    for(int i = n-1; i >= 0; i--) {
      if(s.count(l[i])) break;
      s.insert(l[i]);
    }
    ret = min(ret, n - (int)s.size());
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}