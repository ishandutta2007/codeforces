#include <algorithm>
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
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve(int x, int v) {
  if(x == 1) cout << v;
  else if(x == 2) cout << v << " " << 2*v << endl;
  else if(x == 3) cout << v << " " << v << " " << 3*v << endl;
  else {
    int odd = (x+1)/2;
    for(int i = 0; i < odd; i++) {
      cout << v << " ";
    }
    solve(x-odd, 2*v);
  }
}

void solve() {
  int n;
  cin >> n;
  solve(n, 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}