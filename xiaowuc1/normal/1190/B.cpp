#include <algorithm>
#include <bitset>
#include <cassert>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> query;

const int MAX_SZ = 12;
const int MAX_VAL = 10;

map<vector<int>, bool> seenDP;
map<vector<int>, bool> winDP;

bool cannotMove(vector<int> v) {
  int zero = 0;
  for(int out: v) zero += out == 0;
  if(zero >= 2) return true;
  vector<int> forced;
  for(int i = 1; i < v.size(); i++) {
    if(v[i-1] == v[i]) forced.push_back(v[i]);
  }
  if(forced.size() > 1) return true;
  if(forced.size() == 1) {
    for(int i = 0; i < v.size(); i++) {
      if(v[i] == forced[0]) {
        v[i]--;
        break;
      }
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); i++) {
      if(v[i] == v[i-1]) return true;
    }
    return false;
  }
  for(int i = 0; i < v.size(); i++) {
    if(v[i] == 0) continue;
    if(i == 0 || v[i]-1 != v[i-1]) return false;
  }
  return true;
}

bool fast(vector<int> v) {
  sort(v.begin(), v.end());
  if(cannotMove(v)) return false;
  int numOdd = 0;
  for(int out: v) numOdd += out%2;
  if(v.size()%4 == 0) return numOdd%2 == 1;
  if(v.size()%4 == 1) return numOdd%2 == 1;
  if(v.size()%4 == 2) return numOdd%2 == 0;
  if(v.size()%4 == 3) return numOdd%2 == 0;
  assert(false);
}

bool win(vector<int> v) {
  sort(v.begin(), v.end());
  bool allZero = v.back() == 0;
  if(allZero) return false;
  if(seenDP.count(v)) return winDP[v];
  seenDP[v] = true;
  bool didWin = false;
  for(int i = 0; i < v.size(); i++) {
    vector<int> nv;
    nv = v;
    if(nv[i]) {
      nv[i]--;
      sort(nv.begin(), nv.end());
      bool valid = true;
      for(int j = 1; j < nv.size(); j++) {
        if(nv[j-1] == nv[j]) valid = false;
      }
      if(valid && !win(nv)) didWin = true;
    }
  }
  if(didWin) {
    winDP[v] = true;
  }
  return winDP[v];
}

void dfs(vector<int> v) {
  if(v.size() == MAX_SZ) {
    win(v);
    return;
  }
  int init = 0;
  if(v.size()) init = v.back();
  for(int a = init; a <= MAX_VAL; a++) {
    v.push_back(a);
    dfs(v);
    v.pop_back();
  }
}

void solve() {
  vector<int> v;
  int n;
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  if(fast(v)) cout << "sjfnb\n";
  else cout << "cslnb\n";
  /*
  dfs(v);
  for(auto out: winDP) {
    if(fast(out.first) != out.second) {
      for(int out2: out.first) cout << out2 << " "; cout << endl;
      cout << "fast says " << fast(out.first) << endl;
      cout << "slow says " << out.second << endl;
    }
  }
  */
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}