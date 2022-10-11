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
typedef long double ld;

const int ALICE = 12;
const int BOB = 34;
int a, b;

int winner(int allOther) {
  return allOther%2==0 ? ALICE : BOB;
}

void rsolve() {
  string s;
  cin >> a >> b >> s;
  int onlyBob = 0;
  int both = 0;
  vector<int> others;
  for(int i = 0; i < sz(s);) {
    if(s[i] == 'X') { i++; continue; }
    int j = i+1;
    while(j < sz(s) && s[j] == '.') j++;
    int x = j-i;
    i = j;
    if(x < b) continue;
    if(x >= 2*b) others.push_back(x);
    else if(x < a) onlyBob++;
    else both++;
  }
  if(onlyBob || sz(others) > 1) {
    cout << "NO\n";
    return;
  }
  if(sz(others) == 0) {
    cout << (both%2 == 1 ? "YES" : "NO") << "\n";
    return;
  }
  assert(sz(others) == 1);
  for(int x = 0; x + a <= others[0]; x++) {
    int ob = onlyBob;
    int bb = both;
    if(x >= 2*b) continue;
    if(x >= b) {
      if(x < a) ob++;
      else bb++;
    }
    int xx = others[0] - x - a;
    if(xx >= 2*b) continue;
    if(xx >= b) {
      if(xx < a) ob++;
      else bb++;
    }
    if(ob) continue;
    if(winner(bb) == ALICE) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

void solve() {
  int q;
  cin >> q;
  while(q--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}