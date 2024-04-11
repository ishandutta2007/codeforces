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

int l[1005];
void solve() {
  int n, m;
  cin >> n >> m;
  if(n >= 1100) {
    cout << "0\n";
    return;
  }
  for(int i = 0; i < n; i++) cin >> l[i];
  ll ret = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      ret *= abs(l[i] - l[j]);
      ret %= m;
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}