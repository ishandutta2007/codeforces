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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

bool vsort(vector<int>& a, vector<int>& b) {
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) return a[i] > b[i];
  }
  return false;
}

int ret;
int r, c;

void dfs(vector<vector<int>>& choices, int idx, vector<int>& want) {
  int curr = 0;
  int maxUp = 0;
  bool canImprove = false;
  for(int out: want) {
    curr += out;
    if(idx < choices.size()) {
      if(choices[idx][0] > out) canImprove = true;
      maxUp += max(choices[idx][0], out);
    }
  }
  ret = max(ret, curr);
  if(maxUp <= ret) return;
  if(!canImprove) return;
  for(int j = 0; j < r; j++) {
    vector<int> nwant = want;
    bool didImprove = false;
    for(int a = 0; a < r; a++) {
      didImprove |= choices[idx][(j+a)%r] > nwant[a];
      nwant[a] = max(nwant[a], choices[idx][(j+a)%r]);
    }
    if(didImprove) dfs(choices, idx+1, nwant);
  }
}

int g[5][120];
void realsolve() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<int>> choices;
  for(int j = 0; j < c; j++) {
    int maxi = 0;
    for(int i = 1; i < r; i++) {
      if(g[i][j] > g[maxi][j]) maxi = i;
    }
    vector<int> v;
    for(int i = 0; i < r; i++) {
      v.push_back(g[(i+maxi)%r][j]);
    }
    choices.push_back(v);
  }
  sort(choices.begin(), choices.end(), vsort);
  vector<int> want;
  want.resize(r);
  ret = 0;
  dfs(choices, 0, want);
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}