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
typedef pair<ll, ll> pll;

void rsolve() {
  vector<char> v;
  string s;
  cin >> s;
  for(int i = 0; i < sz(s); i++) v.push_back(s[i]);
  vector<int> ret;
  while(sz(v) >= 3) {
    int i = sz(v) - 3;
    if(sz(v) >= 5 && v[i-2] == 't' && v[i-1] == 'w' && v[i] == 'o' && v[i+1] == 'n' && v[i+2] == 'e') {
      ret.push_back(i);
      v.pop_back(); v.pop_back(); v.pop_back(); v.pop_back(); v.pop_back();
      continue;
    }
    if(v[i] == 't' && v[i+1] == 'w' && v[i+2] == 'o') {
      ret.push_back(i+1);
      v.pop_back(); v.pop_back(); v.pop_back();
      continue;
    }
    if(v[i] == 'o' && v[i+1] == 'n' && v[i+2] == 'e') {
      ret.push_back(i+1);
      v.pop_back(); v.pop_back(); v.pop_back();
      continue;
    }
    v.pop_back();
  }
  cout << sz(ret) << "\n";
  for(int i = 0; i < sz(ret); i++) {
    if(i) cout << " ";
    cout << ret[i]+1;
  } cout << "\n";
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