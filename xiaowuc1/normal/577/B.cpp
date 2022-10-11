#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool dp[1005];
bool ndp[1005];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n && !dp[0]; i++) {
    int k;
    cin >> k;
    k %= m;
    if(i == 0) dp[k] = true;
    else {
      memset(ndp, 0, sizeof(ndp));
      ndp[k] = true;
      for(int a = 0; a < m; a++) {
        if(dp[a]) {
          ndp[a] = true;
          ndp[(a+k)%m] = true;
        }
      }
      memcpy(dp, ndp, sizeof(ndp));
    }
  }
  cout << (dp[0] ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}