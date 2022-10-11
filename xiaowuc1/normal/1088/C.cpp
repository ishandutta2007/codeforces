#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

void inc(vector<int>& v, int n, int inc) {
  printf("%d %d %d\n", 1, n, inc);
  for(int i = 0; i < n; i++) v[i] += inc;
}

void mod(vector<int>& v, int n, int inc) {
  printf("%d %d %d\n", 2, n, inc);
  for(int i = 0; i < n; i++) v[i] %= inc;
}

void solve() {
  int n;
  vector<int> v;
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  printf("%d\n", n+1);
  inc(v, n, 1000000);
  inc(v, n, 1000000);
  int want = 0;
  for(int i = 0; i < n-1; i++) {
    int bestFactor = -1;
    int lowest = 1e9;
    for(int x = 1; x <= 1000000 && lowest != want; x++) {
      int curr = v[i] % x;
      if(curr >= want && curr < lowest) {
        bestFactor = x;
        lowest = curr;
      }
    }
    mod(v, i+1, bestFactor);
    want = v[i] + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}