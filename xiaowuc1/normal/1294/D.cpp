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

bool covered[1000000];
int v[1000000];
void solve() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < x; i++) v[i] = i;
  int ret = 0;
  for(int qq = 0; qq < n; qq++) {
    int curr;
    cin >> curr;
    curr %= x;
    if(v[curr] <= n) {
      covered[v[curr]] = true;
      v[curr] += x;
    }
    while(covered[ret]) ret++;
    cout << ret << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}