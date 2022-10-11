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

void realsolve() {
  int a, b, n;
  cin >> a >> b >> n;
  n %= 3;
  n += 3;
  for(int i = 2; i <= n; i++) {
    int x = a^b;
    a=b;
    b=x;
  }
  cout << b << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}