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
typedef pair<ll, ll> pll;

int thresh;
int l[1 << 22];
bool candel[1 << 22];
priority_queue<int> orphaned;

inline int torem(int curr) {
  // given that we are trying to remove curr, which element do we replace with
  // 0 means we just poof it
  if(l[2*curr] == 0 && l[2*curr+1] == 0) return 0;
  return l[2*curr] > l[2*curr+1] ? (2*curr) : (2*curr+1);
}

inline bool canrem(int curr) {
  int cand = torem(curr);
  if(cand == 0) return curr > thresh;
  return candel[cand];
}

void pullup(int idx) {
  assert(l[idx] > 0);
  candel[idx] = canrem(idx);
  if(idx > 1 && !candel[idx]) {
    orphaned.push(-(idx ^ 1));
  }
}

void rem(int curr) {
  if(l[2*curr] == 0 && l[2*curr+1] == 0) {
    l[curr] = 0;
    candel[curr] = false;
    return;
  }
  if(l[2*curr] > l[2*curr+1]) {
    l[curr] = l[2*curr];
    rem(2*curr);
  }
  else {
    l[curr] = l[2*curr+1];
    rem(2*curr+1);
  }
  pullup(curr);
}

int rem() {
  int ans = -1;
  if(canrem(1)) {
    rem(1);
    ans = 1;
  }
  while(ans == -1 && sz(orphaned)) {
    ans = -orphaned.top();
    if(candel[ans]) {
      rem(ans);
      break;
    }
    orphaned.pop();
    ans = -1;
  }
  int cache = ans;
  while(cache > 1) {
    cache /= 2;
    pullup(cache);
  }
  return ans;
}

void rsolve() {
  int g, h;
  cin >> h >> g;
  while(sz(orphaned)) orphaned.pop();
  thresh = (1 << g) - 1;
  for(int i = 1; i < (1<<h); i++) {
    candel[i] = true;
    cin >> l[i];
  }
  for(int i = (1<<h); i < (2*(1<<h)); i++) {
    candel[i] = false;
    l[i] = 0;
  }
  int ops = (1 << h) - (1 << g);
  vector<int> ret;
  while(ops--) {
    ret.push_back(rem());
    /*
    cerr << "Remove " << ret.back() << endl;
    for(int i = 1; i < (1<<h); i++) cerr << l[i] << " "; cerr << endl;
    for(int i = 1; i < (1<<h); i++) cerr << (int)candel[i] << " "; cerr << endl;
    */
  }
  ll ans = 0;
  for(int i = 1; i < (1<<g); i++) ans += l[i];
  cout << ans << "\n";
  for(int i = 0; i < sz(ret); i++) {
    if(i) cout << " "; cout << ret[i];
  } cout << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}