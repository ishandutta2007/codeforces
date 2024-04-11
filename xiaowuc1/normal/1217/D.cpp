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

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, pll> pdpii;

// NO SAD
int lhs[5001];
int rhs[5001];
int seen[5001];
int n, m;
int ret[5001];

void die() {
  cout << 2 << "\n";
  for(int i = 0; i < m; i++) {
    if(i) cout << " ";
    cout << ret[i];
  }
  cout << "\n";
  exit(0);
}

void dfs(int curr) {
  if(seen[curr] == 2) return;
  if(seen[curr] == 1) die();
  seen[curr] = 1;
  for(int i = 0; i < m; i++) if(lhs[i] == curr) dfs(rhs[i]);
  seen[curr] = 2;
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> lhs[i] >> rhs[i];
    if(lhs[i] < rhs[i]) ret[i] = 1;
    else ret[i] = 2;
  }
  for(int i = 1; i <= n; i++) dfs(i);
  cout << 1 << "\n";
  for(int i = 0; i < m; i++) {
    if(i) cout << " ";
    cout << 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}