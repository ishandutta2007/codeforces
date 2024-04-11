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

string gen(int sz) {
  string ret = "(";
  sz -= 2;
  while(sz > 0) {
    ret += "()";
    sz -= 2;
  }
  ret += ")";
  return ret;
}

void rsolve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  string goal = gen(n - 2*(k-1));
  for(int i = 1; i < k; i++) goal += gen(2);
  vector<pii> ret;
  for(int i = 0; i < n; i++) {
    if(goal[i] == s[i]) continue;
    int j = i+1;
    while(goal[i] != s[j]) j++;
    ret.push_back({i+1, j+1});
    reverse(s.begin()+i, s.begin()+j+1);
  }
  cout << sz(ret) << "\n";
  for(pii out: ret) cout << out.first << " " << out.second << "\n";
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