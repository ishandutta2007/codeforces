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

bool ret[205];
int n;
string s;
void attempt(char ch) {
  for(int i = 0; i < n; i++) ret[i] = (s[i] == ch);
  vector<int> ans;
  for(int i = 0; i+1 < n; i++) {
    if(!ret[i]) {
      ans.push_back(i+1);
      ret[i] ^= true;
      ret[i+1] ^= true;
    }
  }
  if(!ret[n-1]) return;
  else {
    cout << sz(ans) << "\n";
    for(int i = 0; i < sz(ans); i++) {
      if(i) cout << " "; cout << ans[i];
    }
    cout << "\n";
    exit(0);
  }
}

void solve() {
  cin >> n >> s;
  attempt('B');
  attempt('W');
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}