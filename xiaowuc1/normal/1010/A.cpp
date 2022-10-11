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

int liftoff[1005];
int land[1005];
int n, p;
void solve() {
  cin >> n >> p;
  for(int i = 0; i < n; i++) cin >> liftoff[i];
  for(int i = 0; i < n; i++) cin >> land[i];
  vector<double> scale;
  for(int i = 0; i < n; i++) {
    scale.push_back((liftoff[i]-1.)/liftoff[i]);
    int j = (i+1)%n;
    scale.push_back((land[j]-1.)/land[j]);
  }
  double lhs = 0;
  double rhs = 2e9;
  for(int qq = 0; qq < 100; qq++) {
    double mid = (lhs+rhs)/2;
    double curr = mid + p;
    for(double out: scale) curr *= out;
    if(curr >= p) rhs = mid;
    else lhs = mid;
  }
  if(lhs > 1e9) cout << "-1\n";
  else cout << fixed << setprecision(12) << lhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}