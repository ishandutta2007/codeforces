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

mt19937 g1;
string l[10];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    bool initgood = true;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(l[i] == l[j]) initgood = false;
    }
    if(initgood) continue;
    while(true) {
      int idx = (int)g1();
      idx %= 4; idx += 4; idx %= 4;
      int want = (int)g1();
      want %= 10; want += 10; want %= 10;
      string t = l[i].substr(0, idx) + to_string(want) + l[i].substr(idx+1);
      initgood = true;
      for(int j = 0; j < n; j++) {
        if(i == j) continue;
        if(t == l[j]) initgood = false;
      }
      if(initgood) {
        ans++;
        l[i] = t;
        break;
      }
    }
  }
  cout << ans << "\n";
  for(int i = 0; i < n; i++) cout << l[i] << "\n";
}

void solve() {
  int n;
  cin >> n;
  while(n--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}