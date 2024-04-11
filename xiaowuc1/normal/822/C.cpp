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

typedef pair<pii, int> event;

ll best[1000000];
event l[1000000];
void solve() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> l[i].f.f >> l[i].f.s >> l[i].s;
  sort(l, l+n);
  ll ret = 2.1e9;
  memset(best, 63, sizeof(best));
  priority_queue<pair<int, pii>> q; // <-time, duration, value>
  for(int i = 0; i < n; i++) {
    int d = l[i].f.s - l[i].f.f + 1;
    if(d >= x) continue;
    q.emplace(-l[i].f.s, pii(d, l[i].s));
    while(sz(q) && -q.top().f < l[i].f.f) {
      auto curr = q.top(); q.pop();
      best[curr.s.f] = min(best[curr.s.f], (ll)curr.s.s);
    }
    ret = min(ret, l[i].s + best[x-d]);
  }
  if(ret == 2.1e9) ret = -1;
  cout << ret << "\n";
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}