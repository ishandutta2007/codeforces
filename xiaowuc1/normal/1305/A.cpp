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
  int n;
  cin >> n;
  vector<int> a, b;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    b.push_back(t);
  }
  sort(all(a));
  sort(all(b));
  for(int i = 0; i < n; i++) {
    if(i) cout << " "; cout << a[i];
  } cout << "\n";
  for(int i = 0; i < n; i++) {
    if(i) cout << " "; cout << b[i];
  } cout << "\n";
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