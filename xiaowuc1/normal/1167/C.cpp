#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

int par[1000000];
int sz[1000000];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return;
  sz[x] += sz[y];
  par[y] = x;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  while(m--) {
    int k;
    cin >> k;
    vector<int> v;
    for(int i = 0; i < k; i++) {
      int t;
      cin >> t;
      v.push_back(t);
    }
    for(int i = 1; i < k; i++) merge(v[i-1], v[i]);
  }
  for(int i = 1; i <= n; i++) {
    cout << sz[find(i)] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}