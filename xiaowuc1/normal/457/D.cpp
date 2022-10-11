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
typedef pair<int, int> pii;
typedef pair<pii, pii> state;
typedef vector<int> vi;

// NO SAD
long double success[100001];
long double fac[301];

double choose(int n, int k) {
  if(k < 0 || k > n) return 0;
  return fac[n] / (fac[k] * fac[n-k]);
}

void solve() {
  // n by n grid, k numbers up to m are picked
  int n, k, m;
  cin >> n >> m >> k;
  fac[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = fac[i-1] * i;
  }
  success[0] = 1;
  for(int i = 0; i < k; i++) {
    success[i+1] = success[i] * (k-i) / (m-i);
  }
  long double ret = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      long double inc = choose(n, i) * choose(n, j) * success[n*(i+j)-(i*j)];
      ret += inc;
      if(ret >= 1e99) {
        cout << "1e99\n";
        return;
      }
    }
  }
  cout << fixed << setprecision(12) << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}