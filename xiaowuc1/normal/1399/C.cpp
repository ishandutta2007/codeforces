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

void rsolve() {
  int n;
  cin >> n;
  map<int, int> dp;
  while(n--) {
    int x;
    cin >> x;
    dp[x]++;
  }
  int ret = 0;
  for(int s = 2; s <= 100; s++) {
    int cand = 0;
    for(int i = 1; 2*i <= s; i++) {
      if(i+i == s) cand += dp[i] / 2;
      else cand += min(dp[i], dp[s-i]);
    }
    ret = max(ret, cand);
  }
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