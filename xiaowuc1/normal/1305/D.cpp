#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
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

void win(int x) {
  cout << "! " << x << endl;
  exit(0);
}
void ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int ret;
  cin >> ret;
  assert(ret != -1);
  if(x == ret || y == ret) win(ret);
}

vector<int> edges[1005];
bool bad[1005];

vector<int> leaves;

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  while(true) {
    for(int i = 1; i <= n; i++) {
      if(bad[i]) continue;
      int deg = 0;
      for(int out: edges[i]) if(!bad[out]) deg++;
      if(deg <= 1) leaves.push_back(i);
    }
    assert(sz(leaves));
    if(sz(leaves) == 1) win(leaves[0]);
    else {
      ask(leaves[sz(leaves)-2], leaves[sz(leaves)-1]);
      bad[leaves.back()] = true; leaves.pop_back();
      bad[leaves.back()] = true; leaves.pop_back();
      leaves.clear();
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}