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
typedef pair<int, pii> pipii;
typedef vector<int> vi;

// NO SAD
int canDP[14][14][1<<14];
int parDP[14][14][1<<14];
bool seenDP[14][14][1<<14];
vector<int> edges[14];
int n;

void dfs(int curr, int par, int orig, int mask) {
  if(curr == orig) return; // do not loop
  for(int out: edges[curr]) {
    if(out == par) continue;
    if((1<<out) & mask) continue;
    if(canDP[orig][out][mask | (1 << curr)]) continue;
    canDP[orig][out][mask | (1 << curr)] = 1 + canDP[orig][curr][mask];
    parDP[orig][out][mask | (1 << curr)] = curr;
    dfs(out, curr, orig, mask | (1 << curr));
  }
}

void precomp() {
  for(int i = 0; i < n; i++) {
    for(int out: edges[i]) {
      canDP[i][out][0] = 1;
      dfs(out, i, i, 0);
    }
  }
}

int realDP[1 << 14];
pipii parRealDP[1 << 14];

void solve() {
  {
    int m;
    cin >> n >> m;
    while(m--) {
      int a, b;
      cin >> a >> b; a--; b--;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
  }
  precomp();
  for(int i = 0; i < (1<<n); i++) realDP[i] = 1 << 25;
  realDP[1] = 0;
  for(int mask = 0; mask < (1<<n); mask++) {
    if(realDP[mask] == 1 << 25) continue;
    int alternative = (1<<n) - 1;
    alternative &= ~mask;
    for(int cand = alternative; cand > 0; cand = (cand-1) & alternative) {
      for(int x = 0; x < n; x++) {
        if((mask&(1<<x)) == 0) continue;
        for(int y = 0; y < n; y++) {
          if((mask&(1<<y)) == 0) continue;
          if(canDP[x][y][cand] == 0) continue;
          int nDP = realDP[mask] + canDP[x][y][cand];
          if(nDP < realDP[mask | cand]) {
            realDP[mask | cand] = nDP;
            parRealDP[mask | cand] = {cand, {x, y}};
          }
        }
      }
    }
  }
  cout << realDP[(1<<n)-1] << "\n";
  vector<pii> edges;
  int currMask = (1<<n)-1;
  while(currMask != 1) {
    pipii cand = parRealDP[currMask];
    int mask = cand.first;
    int from = cand.second.first;
    int to = cand.second.second;
    while(mask > 0) {
      int parTo = parDP[from][to][mask];
      edges.push_back({parTo, to});
      mask &= ~(1 << parTo);
      to = parTo;
    }
    edges.push_back({from, to});
    currMask = currMask & ~cand.first;
  }
  assert(edges.size() == realDP[(1<<n) - 1]);
  for(pii out: edges) {
    cout << ++out.first << " " << ++out.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}