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
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

bool zero = false;
int seen[1000005];
vector<int> edges[1000005];
pii bfs(int curr) {
  pii ret = pii(0, 0);
  queue<int> q;
  q.push(curr);
  seen[curr] = 1;
  while(sz(q)) {
    curr = q.front(); q.pop();
    if(seen[curr] > 0) ret.f++;
    else ret.s++;
    for(int out: edges[curr]) {
      if(seen[out] == seen[curr]) {
        zero = true;
        return ret;
      }
      if(seen[out] == 0) {
        seen[out] = -seen[curr];
        q.push(out);
      }
    }
  }
  return ret;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  if(m == 0) {
    cout << "3 " << n*(n-1)*(n-2)/6 << "\n";
    return;
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int single = 0;
  ll force = 0;
  for(int i = 1; i <= n; i++) {
    if(seen[i]) continue;
    pii cand = bfs(i);
    if(cand.f == 1 && cand.s == 1) {
      single++;
    }
    else if(cand.f == 1 && cand.s == 0) continue;
    else {
      force += (cand.f) * (cand.f - 1LL) / 2;
      force += (cand.s) * (cand.s - 1LL) / 2;
    }
  }
  if(zero) {
    cout << "0 1\n";
    return;
  }
  if(force == 0) {
    cout << "2 " << m * (n-2) << "\n";
    return;
  }
  cout << "1 " << force << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}