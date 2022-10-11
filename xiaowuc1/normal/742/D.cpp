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
typedef pair<pii, pii> ppiipii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

int n, m, maxW;

int dp[1005];

int w[1005];
int b[1005];

int p[1005];

int find(int x) {
  return p[x] == x ? x : (p[x] = find(p[x]));
}

void merge(int x, int y) {
  p[find(x)] = find(y);
}

void solve() {
  scanf("%d%d%d", &n, &m, &maxW);
  for(int i = 0; i < n; i++) scanf("%d", &w[i]);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);
  for(int i = 0; i < n; i++) p[i] = i;
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    merge(--a, --b);
  }
  for(int id = 0; id < n; id++) {
    vector<pii> choices;
    int totalW=0;
    int totalB=0;
    int amt = 0;
    for(int i = 0; i < n; i++) {
      if(find(i) == id) {
        choices.push_back(pii(w[i], b[i]));
        totalW += w[i];
        totalB += b[i];
        amt++;
      }
    }
    if(amt == 0) continue;
    if(amt > 1) choices.push_back(pii(totalW, totalB));
    int next[1005];
    memset(next, 0, sizeof(next));
    for(int i = 0; i < choices.size(); i++) {
      for(int a = maxW; a >= choices[i].first; a--) {
        next[a] = max(next[a], choices[i].second + dp[a - choices[i].first]);
      }
    }
    for(int a = 0; a <= maxW; a++) {
      dp[a] = max(dp[a], next[a]);
    }
  }
  printf("%d\n", dp[maxW]);
}

int main() {
  solve();
  return 0;
}