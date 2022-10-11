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
  string s, t;
  cin >> s >> t;
  map<char, int> sdp;
  map<char, int> tdp;
  for(int i = 0; i < sz(s); i++) sdp[s[i]]++;
  for(int i = 0; i < sz(t); i++) tdp[t[i]]++;
  ll lhs = 0;
  ll rhs = 1e6;
  while(lhs < rhs) {
    ll mid = (lhs+rhs+1)/2;
    ll have = sdp['?'];
    ll need = 0;
    for(auto out: tdp) {
      need += max(0LL, mid * out.second - sdp[out.first]);
    }
    if(need > have) rhs = mid-1;
    else lhs = mid;
  }
  for(int i = 'a'; i <= 'z'; i++) tdp[i] *= lhs;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] != '?') cout << s[i];
    else {
      bool done = false;
      for(auto out: tdp) {
        if(sdp[out.first] < out.second) {
          cout << out.first;
          sdp[out.first]++;
          done = true;
          break;
        }
      }
      if(!done) cout << 'a';
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}