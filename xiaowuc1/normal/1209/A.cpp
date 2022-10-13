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

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  int ret = 0;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  while(v.size()) {
    ret++;
    int want = v[0];
    for(int i = v.size()-1; i >= 0; i--) {
      if(v[i] % want == 0) {
        v.erase(v.begin() + i);
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}