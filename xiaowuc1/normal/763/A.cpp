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

vector<int> edges[100005];
int n;
int color[100005];

int bad[100005];

void solve() {
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) cin >> color[i];
  int missed = 0;
  for(int i = 1; i <= n; i++) {
    for(int out: edges[i]) {
      if(color[i] == color[out]) continue;
      if(out > i) {
        bad[i]++;
        bad[out]++;
        missed++;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(bad[i] == missed) {
      cout << "YES\n" << i << "\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}