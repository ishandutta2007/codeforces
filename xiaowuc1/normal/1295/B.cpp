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

const int RAGETREE_SZ = 1 << 18;

void rsolve() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  int offset = 0;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] == '0') offset++;
    else offset--;
  }
  int curr = 0;
  ll ret = 0;
  for(int i = 0; i < sz(s); i++) {
    if(offset == 0 && curr == x) {
      cout << "-1\n";
      return;
    }
    int need = x - curr;
    if(offset != 0 && need % offset == 0 && need / offset >= 0) ret++;
    if(s[i] == '0') curr++;
    else curr--;
  }
  cout << ret << "\n";
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