#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
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

mt19937 g1;
pii l[100000];
int ret[100000];
void solve() {
  g1.seed(std::chrono::system_clock::now().time_since_epoch().count());
  clock_t t = clock();
  int k;
  cin >> k;
  int n = 0;
  map<int, vector<int>> dp;
  for(int i = 0; i < k; i++) {
    int t;
    cin >> t;
    dp[t].push_back(i);
  }
  int init = 0;
  for(auto out: dp) {
    if(out.second.size() == 1) {
      l[n++] = {out.first, out.second[0]};
    }
    else {
      vector<int>& v = out.second;
      for(int i = 0; i < out.second.size(); i++) {
        ret[out.second[i]] = (i%2)+1;
      }
      init = __gcd(init, out.first);
    }
  }
  bool done = false;
  while(clock() - t < CLOCKS_PER_SEC * 0.49) {
    shuffle(l, l+n, g1);
    int i = 0;
    int a = init;
    while(i < n && a != 1) {
      a = __gcd(a, l[i++].first);
    }
    if(a != 1) continue;
    int stop = i-1;
    int b = init;
    while(i < n && b != 1) {
      b = __gcd(b, l[i++].first);
    }
    if(b != 1) continue;
    for(int i = 0; i < n; i++) {
      if(i <= stop) ret[l[i].second] = 1;
      else ret[l[i].second] = 2;
    }
    done = true;
  }
  if(!done) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for(int i = 0; i < k; i++) {
    cout << ret[i];
    if(i == n-1) cout << "\n";
    else cout << " ";
  }
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}