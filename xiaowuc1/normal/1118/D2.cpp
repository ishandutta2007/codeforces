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

ll l[1000005];
void solve() {
  int n;
  ll m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll amt = 0;
  for(int i = 0; i < n; i++) amt += l[i];
  if(amt < m) {
    cout << "-1\n";
    return;
  }
  int lhs = 1;
  int rhs = n;
  sort(l, l+n);
  reverse(l, l+n);
  while(lhs < rhs) {
    int mid = (lhs+rhs)/2;
    ll use = 0;
    for(int i = 0; i < n; i++) use += max(0LL, l[i] - (i / mid));
    if(use >= m) rhs = mid;
    else lhs = mid+1;
  }
  cout << lhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}