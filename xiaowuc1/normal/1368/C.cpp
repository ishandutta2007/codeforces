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
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void usacoio(string s) {
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout);
}

int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};
void solve() {
  int n;
  cin >> n;
  set<pii> s;
  for(int i = 0; i <= n; i++) {
    s.insert(pii(i-1,i-1));
    s.insert(pii(i-1,i));
    s.insert(pii(i,i-1));
    s.insert(pii(i,i));
  }
  cout << sz(s) << "\n";
  for(pii out: s) cout << out.f << " " << out.s << "\n";
  /*
  // debug
  int a = 0;
  for(pii out: s) {
    int nn = 0;
    for(int k = 0; k < 4; k++) {
      nn += s.count(pii(out.f + dx[k], out.s + dy[k]));
    }
    if(nn%2) {
      cerr << out.f << " " << out.s << ": " << nn << endl;
    }
    assert(nn%2 == 0);
    if(nn == 4) a++;
  }
  assert(a == n);
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}