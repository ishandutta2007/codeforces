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

#include <unordered_map>

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

bool can[5001][5001];
int want;
int maxmask;
string s;

void go(int offset) {
  char best = 'z' + 1;
  for(int i = 0; i <= maxmask && i + offset < sz(s); i++) {
    if(!can[i+offset][i]) continue;
    best = min(best, s[i+offset]);
    for(int j = 1; j < maxmask; j *= 2) {
      if(i&j) continue;
      can[i+offset+j][i+j] = true;
    }
  }
  assert(best <= 'z');
  cout << best;
  for(int i = 0; i <= maxmask && i + offset < sz(s); i++) {
    if(!can[i+offset][i]) continue;
    if(s[i+offset] != best) continue;
    can[i+offset+1][i] = true;
  }
}

void solve() {
  cin >> s;
  if(sz(s) == 1) {
    cout << s << "\n";
    return;
  }
  want = sz(s);
  for(int i = 0; (1<<i) < want; i++) {
    want -= (1<<i);
    maxmask |= 1 << i;
  }
  can[0][0] = true;
  for(int i = 0; i < want; i++) go(i); cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}