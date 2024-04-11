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
typedef pair<pii, pii> state;
typedef vector<vector<ll>> matrix;

bool fast(vector<int> v) {
  bool lose = false;
  map<int, int> dp;
  int minSeen = 1e9;
  for(int i = 0; i < v.size(); i++) {
    dp[v[i]]++;
    minSeen = min(minSeen, v[i]);
  }
  return dp[minSeen] <= v.size() / 2;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  if(!fast(v)) cout << "Bob\n";
  else cout << "Alice\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}