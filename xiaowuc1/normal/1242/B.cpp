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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n, m;
set<int> bad[200005];
int ret;
vector<pii> order;

bool seen[200005];
vector<int> explicitFree;

void solve(int cand) {
  if(seen[cand]) return;
  int sz = 0;
  seen[cand] = true;
  queue<int> q;
  q.push(cand);
  while(!q.empty()) {
    int curr = q.front();
    sz++;
    q.pop();
    vector<int> nexp;
    for(int out: explicitFree) {
      if(seen[out]) continue;
      if(bad[curr].count(out)) {
        nexp.push_back(out);
      }
      else {
        seen[out] = true;
        q.push(out);
      }
    }
    explicitFree = nexp;
  }
  ret++;
}

void solve() {
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    bad[a].insert(b);
    bad[b].insert(a);
  }
  for(int i = 1; i <= n; i++) {
    explicitFree.push_back(i);
    order.push_back(pii(bad[i].size(), i));
  }
  ret = -1;
  sort(order.begin(), order.end());
  for(pii out: order) {
    solve(out.second);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}