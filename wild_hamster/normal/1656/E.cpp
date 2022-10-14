#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;

ll n, t, k, x, y, m;
ll a[200500];
vector<ll> g[100500];

void dfs(ll v, ll f, ll d) {
  if (v == 1) {
    a[v] = g[v].size();
  } else {
    a[v] = g[v].size();
  }
  if (d % 2 != 0) {
    a[v] = -a[v];
  }
  for (auto to : g[v]) {
    if (to != f) {
      dfs(to, v, d + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(1, -1, 0);
    for (int i = 0; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}