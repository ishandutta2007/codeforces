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

vector<int> v;
void solve() {
  int n, k;
  cin >> n >> k;
  {
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) v.push_back(s[i] - '0');
  }
  vector<int> pref;
  for(int i = 0; i < k; i++) {
    pref.push_back(v[i]);
  }
  while(sz(pref) < sz(v)) {
    pref.push_back(pref[sz(pref)-k]);
  }
  if(pref >= v) {
    cout << sz(pref) << "\n";
    for(int out: pref) cout << out;
    cout << "\n";
    return;
  }
  pref.resize(k);
  int rhs = sz(pref)-1;
  while(pref[rhs] == 9) {
    pref[rhs] = 0;
    rhs--;
  }
  pref[rhs]++;
  while(sz(pref) < sz(v)) {
    pref.push_back(pref[sz(pref)-k]);
  }
  assert(pref >= v);
  cout << sz(pref) << "\n";
  for(int out: pref) cout << out;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}