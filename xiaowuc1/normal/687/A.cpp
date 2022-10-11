#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

vector<int> edges[100005];
int dp[100005];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    if(dp[i]) continue;
    dp[i] = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
      int curr = q.front();
      q.pop();
      for(int a = 0; a < edges[curr].size(); a++) {
        int nn = edges[curr][a];
        if(dp[nn] == dp[curr]) {
          printf("-1\n");
          return;
        }
        if(dp[nn] == 0) {
          dp[nn] = -dp[curr];
          q.push(nn);
        }
      }
    }
  }
  vector<int> a, b;
  for(int i = 1; i <= n; i++) {
    if(dp[i] > 0) a.push_back(i);
    else b.push_back(i);
  }
  printf("%d\n", a.size());
  for(int i = 0; i < a.size(); i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("%d\n", b.size());
  for(int i = 0; i < b.size(); i++) {
    printf("%d ", b[i]);
  }
  printf("\n");

}

int main() {
  /*
  freopen("integral.in","r",stdin);
  freopen("integral.out","w",stdout);
  */
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}