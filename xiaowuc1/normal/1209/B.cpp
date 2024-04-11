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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int a[105];
int b[105];
bool on[105];
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if(s[i] == '1') on[i] = true;
  }
  int ret = 0;
  for(int t = 0; t <= 1e6; t++) {
    int curr = 0;
    for(int i = 0; i < n; i++) {
      curr += on[i];
      if(t >= b[i] && (t-b[i])%a[i] == 0) on[i] ^= true;
    }
    ret = max(ret, curr);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}