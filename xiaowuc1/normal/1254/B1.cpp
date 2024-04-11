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

int n;
int l[1000005];
void solve() {
  cin >> n;
  ll tot = 0;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    tot += l[i];
  }
  if(tot == 1) {
    cout << "-1\n";
    return;
  }
  ll ret = 1e18;
  for(ll x = 2; tot > 1; x++) {
    if(x*x > tot) x = tot;
    if(tot%x) continue;
    while(tot%x==0) tot /= x;
    ll cand = 0;
    ll curr = 0;
    for(int i = 0; i < n; i++) {
      curr += l[i];
      curr %= x;
      cand += min(curr, x - curr);
    }
    ret = min(ret, cand);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}