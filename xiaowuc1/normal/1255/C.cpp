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
typedef pair<ll, ll> pll;

const ll INF = 1LL << 40;

map<pii, vector<int>> dp;
int appear[1000000];
int n;

void solve() {
  cin >> n;
  for(int i = 0; i < n-2; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[{a,b}].push_back(c);
    dp[{b,a}].push_back(c);
    dp[{a,c}].push_back(b);
    dp[{c,a}].push_back(b);
    dp[{b,c}].push_back(a);
    dp[{c,b}].push_back(a);
    appear[a]++;
    appear[b]++;
    appear[c]++;
  }
  int start = 1;
  while(appear[start] > 1) start++;
  int start2 = 1;
  while(appear[start2] != 2 || !dp.count({start, start2})) start2++;
  vector<int> ret;
  ret.push_back(start);
  ret.push_back(start2);
  ret.push_back(dp[{start, start2}][0]);
  while(sz(ret) < n) {
    vector<int> cands = dp[{ret[sz(ret)-2], ret[sz(ret)-1]}];
    if(cands[0] != ret[sz(ret)-3]) ret.push_back(cands[0]);
    else ret.push_back(cands[1]);
  }
  for(int i = 0; i < sz(ret); i++) {
    if(i) cout << " "; cout << ret[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}