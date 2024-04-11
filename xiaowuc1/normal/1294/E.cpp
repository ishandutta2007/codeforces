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

void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> g;
  for(int i = 0; i < r; i++) {
    vector<int> v(c);
    for(int j = 0; j < c; j++) {
      cin >> v[j];
      v[j]--;
    }
    g.push_back(v);
  }
  int ret = 0;
  for(int j = 0; j < c; j++) {
    vector<int> matches(r);
    map<int, int> valToExpRow;
    for(int i = 0; i < r; i++) {
      valToExpRow[i*c+j] = i;
    }
    for(int i = 0; i < r; i++) {
      if(!valToExpRow.count(g[i][j])) continue;
      int idx = valToExpRow[g[i][j]];
      int offset = i-idx;
      if(offset < 0) offset += r;
      matches[offset]++;
    }
    int cand = 1e9;
    for(int i = 0; i < r; i++) {
      cand = min(cand, i + r - matches[i]);
    }
    ret += cand;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}