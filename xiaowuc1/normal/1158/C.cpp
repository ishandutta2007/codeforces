#include <algorithm>
#include <bitset>
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
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int firstSeen[500005];
void realsolve() {
  int n;
  cin >> n;
  for(int i = 0; i <= n; i++) firstSeen[i] = -1;
  vector<int> nxt;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    nxt.push_back(--t);
    if(t < 0) continue;
    if(firstSeen[t] < 0) firstSeen[t] = i;
  }
  vector<int> ret;
  ret.resize(n);
  int nextVal = 1;
  for(int i = n-1; i >= 0; i--) {
    if(firstSeen[i] >= 0) continue;
    ret[i] = nextVal++;
    int cand = nxt[i];
    int prev = i;
    while(cand < n && ret[cand] == 0 && firstSeen[cand] == prev) {
      ret[cand] = nextVal++;
      cand = nxt[cand];
      prev = nxt[prev];
    }
  }
  stack<pii> s;
  for(int i = 0; i < n; i++) {
    while(!s.empty() && s.top().second == i) s.pop();
    if(nxt[i] < 0) continue;
    if(s.empty()) {
      s.push({i, nxt[i]});
      continue;
    }
    if(s.top().second < nxt[i]) {
      cout << "-1\n";
      return;
    }
    s.push({i, nxt[i]});
  }
  for(int out: ret) cout << out << " ";
  cout << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}