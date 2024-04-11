#include <algorithm>
#include <bitset>
#include <cassert>
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

string g[1005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
  }
  ll ret = 0;
  for(int j = 0; j < m; j++) {
    int inc;
    cin >> inc;
    map<char, int> dp;
    for(int i = 0; i < n; i++) {
      dp[g[i][j]]++;
    }
    int out = 0;
    for(auto out2: dp) out = max(out, out2.second);
    ret += inc * out;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}