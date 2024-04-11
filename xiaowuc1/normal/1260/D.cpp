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
typedef pair<pii, int> trap;

bool trapsort(trap a, trap b) {
  return a.first < b.first;
  /*
  if(a.first.first != b.first.first) return a.first.first < b.first.first;
  return a.first.second < b.first.second;
  */
}

void solve() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  m++;
  vector<int> v;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(all(v));
  reverse(all(v));
  vector<trap> traps;
  for(int i = 0; i < k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    traps.push_back(trap(pii(a, b), c));
  }
  sort(all(traps), trapsort);
  int lhs = 0;
  int rhs = sz(v);
  while(lhs < rhs) {
    int mid = (lhs+rhs+1)/2;
    int thresh = v[mid-1];
    vector<pii> bad;
    for(trap cand: traps) {
      if(cand.second > thresh) {
        if(bad.empty() || cand.first.second > bad.back().second) {
          bad.push_back(cand.first);
        }
      }
    }
    int travel = 0;
    int currS = 0;
    int you = 0;
    for(pii out: bad) {
      assert(you >= currS);
      if(you < out.first-1) {
        travel += you - currS;
        int inc = out.first-1 - currS;
        travel += inc;
        currS += inc;
        you = out.first-1;
      }
      travel += out.second - you;
      you = out.second;
    }
    travel += you - currS + m - currS;
    if(travel <= t) lhs = mid;
    else rhs = mid - 1;
  }
  cout << lhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}