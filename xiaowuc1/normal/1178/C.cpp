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
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;

// 0 is TL, BR
// 1 is TR, BL
// 2 is BR, TL
// 3 is BL, TR

bool top(int idx) {
  return idx == 0 || idx == 1;
}
bool right(int idx) {
  return idx == 1 || idx == 2;
}
bool bot(int idx) {
  return idx == 2 || idx == 3;
}
bool left(int idx) {
  return idx == 3 || idx == 0;
}

ll slow(int r, int c) {
  ll ret = 0;
  for(int mask = 0; mask < (1 << (2*r*c)); mask++) {
    // cout << r << " " << c << " " << mask << endl;
    vector<vector<int>> g;
    int t = mask;
    for(int i = 0; i < r; i++) {
      vector<int> v;
      for(int j = 0; j < c; j++) {
        v.push_back(t%4);
        t /= 4;
      }
      g.push_back(v);
    }
    bool bad = false;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(i+1 < r && bot(g[i][j]) == top(g[i+1][j])) {
           bad = true;
        }
        if(j+1 < c && right(g[i][j]) == left(g[i][j+1])) {
          bad = true;
        }
      }
    }
    if(!bad) ret++;
  }
  return ret;
}

void solve() {
  int r, c;
  cin >> r >> c;
  int e = r+c;
  ll ret = 1;
  while(e--) {
    ret *= 2;
    ret %= 998244353;
  }
  cout << ret << "\n";
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