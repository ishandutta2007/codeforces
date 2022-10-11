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
typedef pair<pii, int> config;

int n,v;
int l[30005];
void solve() {
  cin >> n >> v;
  for(int i = 0; i < n; i++) {
    int d, x;
    cin >> d >> x;
    l[d] += x;
  }
  int ret = 0;
  for(int i = 1; i <= 3002; i++) {
    int can = v;
    int take = min(l[i-1], can);
    l[i-1] -= can;
    ret += take;
    can -= take;
    take = min(l[i], can);
    l[i] -= take;
    ret += take;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}