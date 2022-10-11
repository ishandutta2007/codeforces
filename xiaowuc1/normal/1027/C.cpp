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

void rsolve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(all(v));
  vector<int> twos;
  for(int i = 0; i+1 < n; i++) {
    if(v[i+1] == v[i]) twos.push_back(v[i]);
  }
  twos.resize(unique(all(twos)) - twos.begin());
  vector<int> fours;
  for(int i = 0; i+3 < n; i++) {
    if(v[i+3] == v[i]) fours.push_back(v[i]);
  }
  fours.resize(unique(all(fours)) - fours.begin());
  vector<int> ret;
  double ans = 1e18;
  for(int i = 1; i < sz(twos); i++) {
    double p = 2 * (twos[i] + twos[i-1]);
    double a = twos[i] * (double)twos[i-1];
    if(p*p < a * ans) {
      ans = p*p/a;
      ret.clear();
      ret.push_back(twos[i-1]);
      ret.push_back(twos[i-1]);
      ret.push_back(twos[i]);
      ret.push_back(twos[i]);
    }
  }
  for(int i = 0; i < sz(fours); i++) {
    double p = 4 * (fours[i]);
    double a = fours[i] * (double)fours[i];
    if(p*p < a * ans) {
      ans = p*p/a;
      ret.clear();
      ret.push_back(fours[i]);
      ret.push_back(fours[i]);
      ret.push_back(fours[i]);
      ret.push_back(fours[i]);
    }
  }
  for(int i = 0; i < 4; i++) {
    if(i) cout << " "; cout << ret[i];
  }
  cout << "\n";
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