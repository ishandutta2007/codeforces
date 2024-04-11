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

void rsolve() {
  vector<int> v;
  v.resize(3);
  cin >> v[0];
  cin >> v[1];
  cin >> v[2];
  sort(all(v));
  cout << min(v[0] + v[1], (v[0] + v[1] + v[2]) / 2) << "\n";
}

void solve() {
  int n;
  cin >> n;
  while(n--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}