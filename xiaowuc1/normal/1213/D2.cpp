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
typedef pair<ll, ll> pll;

const ll INF = 1LL << 40;

vector<int> v[200005];
void solve() {
  int n, k;
  cin >> n >> k;
  while(n--) {
    int x;
    cin >> x;
    int add = 0;
    while(true) {
      v[x].push_back(add++);
      if(x == 0) break;
      x /= 2;
    }
  }
  int ret = 1e9;
  for(int x = 0; x <= 200000; x++) {
    if(sz(v[x]) < k) continue;
    sort(all(v[x]));
    int cand = 0;
    for(int a = 0; a < k; a++) cand += v[x][a];
    ret = min(ret, cand);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}