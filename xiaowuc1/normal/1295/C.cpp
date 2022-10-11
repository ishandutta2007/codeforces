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

set<int> locs[26];
void rsolve() {
  string s, t;
  cin >> s >> t;
  for(int i = 0; i < 26; i++) locs[i].clear();
  for(int i = 0; i < sz(s); i++) locs[s[i] - 'a'].insert(i);
  int curr = -1;
  int ret = 1;
  for(int i = 0; i < sz(t); i++) {
    if(locs[t[i]-'a'].empty()) {
      cout << "-1\n";
      return;
    }
    auto it = locs[t[i]-'a'].upper_bound(curr);
    if(it == locs[t[i]-'a'].end()) {
      ret++;
      it = locs[t[i]-'a'].begin();
    }
    curr = *it;
  }
  cout << ret << "\n";
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