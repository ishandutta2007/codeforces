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
#include <unordered_map>
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
typedef pair<double, pii> event;

int from[100005];
void solve() {
  int n;
  cin >> n;
  set<pii> a, b;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    from[t] = i;
    a.insert({i, t});
  }
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    b.insert({i, t});
  }
  int ret = 0;
  for(auto out: b) {
    if(a.begin()->second != out.second) {
      ret++;
    }
    a.erase({from[out.second], out.second});
    a.erase(out);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}