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

int last[200005];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) last[i] = 0;
  int ret = 1e9;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if(last[x]) {
      ret = min(ret, i - last[x] + 1);
    }
    last[x] = i;
  }
  if(ret == 1e9) ret = -1;
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