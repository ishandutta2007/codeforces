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

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
ll lens[100005];

char solve(int n, ll i) {
  if(n == 0) {
    if(i >= sz(f0)) return '.';
    return f0[i];
  }
  assert(n > 0);
  if(i < sz(a)) return a[i];
  i -= sz(a);
  if(lens[n-1] > i) return solve(n-1, i);
  i -= lens[n-1];
  if(i < sz(b)) return b[i];
  i -= sz(b);
  if(lens[n-1] > i) return solve(n-1, i);
  i -= lens[n-1];
  if(i < sz(c)) return c[i];
  return '.';
}

void rsolve() {
  int n;
  ll i;
  cin >> n >> i;
  i--;
  cout << solve(n, i);
}

void solve() {
  lens[0] = sz(f0);
  for(int i = 1; i <= 100000; i++) {
    if(lens[i-1] <= 2e18) {
      lens[i] = sz(a) + sz(b) + sz(c) + 2 * lens[i-1];
    }
    else {
      lens[i] = 1e18;
    }
  }
  int t;
  cin >> t;
  while(t--) rsolve();
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}