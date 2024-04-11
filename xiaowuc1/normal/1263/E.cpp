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
typedef pair<int, pii> state;

const int RAGETREE_SZ = 1 << 20;
state ragetree[2 * RAGETREE_SZ]; // <current sum, <min sum, max sum>>

state merge(state a, state b) {
  int delta = a.first + b.first;
  int lowest = min(a.second.first, a.first + b.second.first);
  int highest = max(a.second.second, a.first + b.second.second);
  return {delta, pii(lowest, highest)};
}

void upd(int idx, int val) {
  idx += RAGETREE_SZ;
  ragetree[idx] = {val, pii{val, val}};
  while(idx > 1) {
    idx /= 2;
    ragetree[idx] = merge(ragetree[2*idx], ragetree[2*idx+1]);
  }
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int pos = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'R') pos++;
    else if(s[i] == 'L') pos = max(0, pos-1);
    else {
      if(s[i] == '(') upd(pos, 1);
      else if(s[i] == ')') upd(pos, -1);
      else upd(pos, 0);
    }
    if(i) cout << " ";
    if(ragetree[1].first || ragetree[1].second.first < 0) cout << "-1";
    else cout << ragetree[1].second.second;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}