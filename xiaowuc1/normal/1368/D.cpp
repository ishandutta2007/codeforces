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

ll l[200005];
int bits[20];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for(int a = 0; a < 20; a++) {
      if(x&(1<<a)) bits[a]++;
    }
  }
  for(int x = 19; x >= 0; x--) {
    for(int i = n-1; i >= 0 && bits[x] > 0; i--) {
      l[i] |= 1 << x;
      bits[x]--;
    }
  }
  ll ret = 0;
  for(int i = 0; i < n; i++) ret += l[i] * l[i];
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}