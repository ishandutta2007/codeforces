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
#include <unordered_map>
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
typedef pair<int, pii> state;
typedef pair<double, pii> event;

ll l[100005];
const int MAX_D = 17;
ll st[100005][MAX_D];

int n;
int ret[100005];
void solve() {
  cin >> n;
  ll lhsv = 1e18;
  ll rhsv = 0;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    l[i] *= 2;
    lhsv = min(lhsv, l[i]);
    rhsv = max(rhsv, l[i]);
    st[i][0] = l[i];
  }
  if(2*lhsv >= rhsv) {
    for(int i = 0; i < n; i++) {
      if(i) cout << " ";
      cout << -1;
    }
    cout << "\n";
    return;
  }
  memset(ret, 1, sizeof(ret));
  for(int d = 1; d < MAX_D; d++) {
    for(int i = 0; i < n; i++) {
      int j = (i + (1 << (d - 1))) % n;
      st[i][d] = max(st[i][d-1], st[j][d-1]);
    }
  }
  for(int i = 0; i < n; i++) {
    if(2*l[i] >= rhsv) continue;
    int d = MAX_D-1;
    int amt = 0;
    int curr = i;
    while(d >= 0) {
      int prev = (curr - (1 << d)) % n;
      if(prev < 0) prev += n;
      if(st[prev][d] <= 2 * l[i]) {
        amt += 1 << d;
        curr = prev;
      }
      else {
        d--;
      }
    }
    amt++;
    curr = (curr+n-1)%n;
    ret[curr] = min(ret[curr], amt);
  }
  for(int qq = 0; qq < 2; qq++) {
    for(int i = n-1; i >= 0; i--) {
      int j = (i+1)%n;
      ret[i] = min(ret[i], ret[j]+1);
    }
  }
  for(int i = 0; i < n; i++) {
    if(i) cout << " ";
    cout << ret[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}