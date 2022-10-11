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

int l[105];
void solve() {
  int n;
  cin >> n;
  int total = 0;
  int chosen = 0;
  vector<int> ret;
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    total += l[i];
    if(i == 1 || l[i] * 2 <= l[1]) {
      chosen += l[i];
      ret.push_back(i);
    }
  }
  if(2*chosen > total) {
    cout << ret.size() << "\n";
    for(int out: ret) {
      cout << out << " ";
    }
    cout << "\n";
  }
  else {
    cout << "0\n";
  }
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