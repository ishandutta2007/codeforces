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
  string s, t;
  cin >> s >> t;
  int ret = 0;
  int tSum = 0;
  for(int i = 0; i < t.size(); i++) tSum += t[i] - '0';
  int sSum = 0;
  for(int i = 0; i < s.size(); i++) {
    if(i >= t.size()) {
      sSum -= s[i-t.size()] - '0';
    }
    sSum += s[i] - '0';
    if(sSum%2 == tSum%2 && i >= t.size()-1) ret++;
  }
  cout << ret << "\n";
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