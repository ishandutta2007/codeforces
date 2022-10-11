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
#define derr if(0) cerr
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int l[505];
vector<int> v[2];
bool issorted(vector<int>& v) {
  for(int i = 1; i < sz(v); i++) if(v[i] < v[i-1]) return false;
  return true;
}
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  v[0].clear();
  v[1].clear();
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[x].push_back(l[i]);
  }
  if(sz(v[0]) == 0) {
    if(!issorted(v[1])) {
      cout << "No\n";
      return;
    }
  }
  if(sz(v[1]) == 0) {
    if(!issorted(v[0])) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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