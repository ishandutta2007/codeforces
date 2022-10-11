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

// v[i] is the length of the longest proper prefix of the substring [0..i] which is a suffix of the string
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


string s;
int dp[8001];

inline int getContrib(int sz) {
  int ret = 1;
  while(sz >= 10) {
    ret++;
    sz /= 10;
  }
  return ret;
}

void solve() {
  cin >> s;
  memset(dp, 1, sizeof(dp));
  dp[0] = 0;
  for(int i = 0; i < sz(s); i++) {
    vector<int> pff = prefix_function(s.substr(i));
    for(int j = i+1; j <= sz(s); j++) {
      int len = j - i;
      int last = pff[j-i-1];
      if(len % (len-last) == 0) {
        dp[j] = min(dp[j], dp[i] + len-last + getContrib(len/(len-last)));
      }
      else {
        dp[j] = min(dp[j], dp[i] + len + 1);
      }
    }
  }
  cout << dp[sz(s)] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}