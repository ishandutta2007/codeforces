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
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

void die() {
  cout << "-1\n";
  exit(0);
}

int l[100005];
ll can[100005];
int ret[100005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> l[i];
    can[i+1] = can[i] + l[i];
  }
  if(can[m] < n) die();
  int needtocolor = n;
  for(int i = m-1; i >= 0; i--) {
    if(i + l[i] > n) die();
    int v = max(i+1, needtocolor - l[i] + 1);
    ret[i] = v;
    needtocolor = v-1;
  }
  for(int i = 0; i < m; i++) {
    if(i) cout << " ";
    cout << ret[i];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}