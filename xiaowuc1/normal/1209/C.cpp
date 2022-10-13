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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

void realsolve() {
  int n;
  cin >> n;
  string s;
  vector<int> ret;
  cin >> s;
  for(int i = 0; i < s.size(); i++) ret.push_back(2);
  int rhsPaint = -1;
  bool done = false;
  for(char want = '0'; want <= '9'; want++) {
    bool seen = false;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == want) {
        if(i >= rhsPaint) {
          rhsPaint = i;
          ret[i] = 1;
        }
        else {
          seen = true;
        }
      }
    }
    if(seen) break;
  }
  vector<char> fin;
  for(int i = 0; i < ret.size(); i++) if(ret[i] == 1) fin.push_back(s[i]);
  for(int i = 0; i < ret.size(); i++) if(ret[i] == 2) fin.push_back(s[i]);
  for(int i = 1; i < fin.size(); i++) {
    if(fin[i] < fin[i-1]) {
      cout << "-\n";
      return;
    }
  }
  for(int out: ret) cout << out;
  cout << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}