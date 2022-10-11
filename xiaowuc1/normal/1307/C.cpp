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
typedef vector<vector<ll>> matrix;

ll f[256];
void solve() {
  string s;
  cin >> s;
  ll ret = 0;
  // one case
  for(int i = 0; i < sz(s); i++) f[s[i]]++;
  for(int i = 0; i < 256; i++) ret = max(ret, f[i]);
  // two case, same
  for(int i = 0; i < 256; i++) {
    ret = max(ret, (f[i]) * (f[i]-1) / 2);
  }
  // two case, distinct
  for(char a = 'a'; a <= 'z'; a++) {
    for(char b = 'a'; b <= 'z'; b++) {
      if(a == b) continue;
      int ac = 0;
      ll cand = 0;
      for(int i = 0; i < sz(s); i++) {
        if(s[i] == a) ac++;
        else if(s[i] == b) cand += ac;
      }
      ret = max(ret, cand);
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}