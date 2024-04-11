#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

// NO SAD

int g[1005][1005];
void solve() {
  int n;
  cin >> n;
  int idx = 0;
  for(int i = 0; i < n; i+=2) {
    for(int j = 0; j < n; j+=2) {
      g[i][j] = idx++;
      g[i][j+1] = idx++;
      g[i+1][j+1] = idx++;
      g[i+1][j] = idx++;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << g[i][j];
      if(j == n-1) cout << "\n";
      else cout << " ";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}