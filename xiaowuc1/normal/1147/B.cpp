#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

int n, m;
vector<int> dists[100005];

void win() {
  cout << "Yes\n";
  exit(0);
}

void solve() {
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    a--;
    b--;
    dists[a].push_back(b-a);
    dists[b].push_back(n-(b-a));
  }
  for(int i = 0; i < n; i++) sort(dists[i].begin(), dists[i].end());
  map<vector<int>, int> dp;
  for(int i = 0; i < n; i++) {
    dp[dists[i]]++;
  }
  int period = 0;
  for(auto x: dp) {
    period = __gcd(period, x.second);
  }
  for(int i = 1; i < n; i++) {
    int actualPeriod = n / __gcd(n, i);
    if(period % actualPeriod) continue;
    bool good = true;
    for(int a = 0; good && a < n; a++) {
      int na = (a+i);
      if(na >= n) na -= n;
      good &= dists[a].size() == dists[na].size() && dists[a] == dists[na];
    }
    if(good) win();
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}