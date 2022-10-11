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
  string s;
  cin >> s;
  int n = sz(s);
  vector<int> best;
  for(int i = 0; i < n; i++) {
    vector<int> a, b;
    for(int j = 0; j < n; j++) {
      if(j <= i && s[j] == '(') a.push_back(j);
      if(j > i && s[j] == ')') b.push_back(j);
    }
    int want = min(sz(a), sz(b));
    sort(all(b));
    reverse(all(b));
    if(want == 0) continue;
    a.resize(want);
    b.resize(want);
    reverse(all(b));
    if(2*want > sz(best)) {
      best.clear();
      for(int out: a) best.push_back(out);
      for(int out: b) best.push_back(out);
    }
  }
  if(sz(best) == 0) {
    cout << "0\n";
    return;
  }
  cout << 1 << "\n";
  cout << sz(best) << "\n";
  for(int i = 0; i < sz(best); i++) {
    if(i) cout << " "; cout << ++best[i];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}