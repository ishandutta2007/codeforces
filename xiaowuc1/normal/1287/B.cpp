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

#include <unordered_map>

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

string l[1500];
void solve() {
  int n, k;
  cin >> n >> k;
  set<string> all;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    all.insert(l[i]);
  }
  sort(l, l+n);
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      string want = "";
      for(int a = 0; a < k; a++) {
        if(l[i][a] == l[j][a]) want += l[i][a];
        else want += (char)('S' + 'E' + 'T' - l[i][a] - l[j][a]);
      }
      ret += all.count(want);
    }
  }
  cout << ret/3 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}