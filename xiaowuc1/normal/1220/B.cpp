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
typedef pair<double, double> pdd;
typedef pair<int, pii> pipii;

ll g[1024][1024];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
    cin >> g[i][j];
  }
  for(int i = 0; i < n; i++) {
    int a = (i+n-1)%n;
    int b = (i+1)%n;
    ll ret = g[a][i] * g[i][b];
    ret /= g[a][b];
    if(i) cout << " ";
    cout << (ll)sqrt(ret);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}