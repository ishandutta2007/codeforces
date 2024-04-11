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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> inc;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ret += min(a, b);
    inc.push_back(min(2*a,b) - min(a,b));
  }
  sort(all(inc));
  while(sz(inc) && k) {
    k--;
    ret += inc.back();
    inc.pop_back();
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}