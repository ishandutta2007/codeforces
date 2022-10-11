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
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

ll l[505];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ret = max(ret, l[i]);
    for(int j = 0; j < i; j++) {
      ret = max(ret, l[i] | l[j]);
      for(int k = 0; k < j; k++) {
        ret = max(ret, l[i] | l[j] | l[k]);
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