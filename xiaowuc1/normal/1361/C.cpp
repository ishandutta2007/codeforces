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
typedef vector<vector<ll>> matrix;

int l[1 << 20];
int n;
vector<int> eulerstack;
vector<pii> edges[1 << 20];
int edgeused[1 << 20];
int currid;

void euler(int curr) {
  stack<int> st;
  st.push(curr);
  while(sz(st)) {
    curr = st.top();
    bool found = false;
    while(sz(edges[curr])) {
      pii now = edges[curr].back(); edges[curr].pop_back();
      if(edgeused[now.second] == currid) continue;
      edgeused[now.second] = currid;
      edgeused[now.second^1] = currid;
      found = true;
      st.push(now.first);
      break;
    }
    if(!found) {
      eulerstack.push_back(curr);
      st.pop();
    }
  }
}

vector<int> realret;
int seen[1 << 20];
bool can(int cand) {
  currid++;
  int eid = 0;
  int mod = 1 << cand;
  for(int i = 0; i < mod; i++) edges[i].clear();
  for(int i = 0; i < n; i += 2) {
    int a = l[i] % mod;
    int b = l[i+1] % mod;
    edges[a].emplace_back(b, eid++);
    edges[b].emplace_back(a, eid++);
  }
  for(int i = 0; i < mod; i++) {
    if(sz(edges[i]) % 2) return false;
  }
  int ans = 0;
  while(sz(edges[ans]) == 0) ans++;
  eulerstack.clear();
  euler(ans);
  if(sz(eulerstack) < n/2) return false;
  if(sz(eulerstack) > n/2 && eulerstack[0] != eulerstack[n/2]) return false;
  map<pii, vector<pii>> force;
  for(int i = 0; i < n; i += 2) {
    force[pii(l[i]%mod, l[i+1]%mod)].emplace_back(i, i+1);
    force[pii(l[i+1]%mod, l[i]%mod)].emplace_back(i+1, i);
  }
  vector<int> ret;
  for(int i = 0; i < n/2; i++) {
    int j = (i+1);
    if(j == sz(eulerstack)) j = 0;
    pii want = {eulerstack[i], eulerstack[j]};
    bool found = false;
    while(sz(force[want])) {
      pii key = force[want].back();
      force[want].pop_back();
      if(seen[key.first] != currid && seen[key.second] != currid) {
        seen[key.first] = currid;
        seen[key.second] = currid;
        ret.push_back(key.first);
        ret.push_back(key.second);
        found = true;
        break;
      }
    }
    if(!found) return false;
  }
  ret.swap(realret);
  return true;
}

void solve() {
  cin >> n;
  n *= 2;
  for(int i = 0; i < n; i++) cin >> l[i];
  int ans = 20;
  while(!can(ans)) ans--;
  cout << ans << "\n";
  for(int i = 0; i < sz(realret); i++) {
    cout << realret[i]+1 << " \n"[i == sz(realret)-1];
  }
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}