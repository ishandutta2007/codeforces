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

int par[200005];
vector<int> v[26];

int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return false;
  par[x] = y;
  return true;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    set<int> x;
    for(int a = 0; a < sz(s); a++) x.insert(s[a] - 'a');
    for(int out: x) v[out].push_back(i);
  }
  for(int i = 0; i < n; i++) par[i] = i;
  int ret = n;
  for(int i = 0; i < 26; i++) {
    for(int a = 1; a < sz(v[i]); a++) {
      ret -= merge(v[i][a-1], v[i][a]);
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}