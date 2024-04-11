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

int sz[5000];
int co[5000];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> sz[i];
  for(int i = 0; i < n; i++) cin >> co[i];
  int ret = 5e8;
  for(int j = 0; j < n; j++) {
    int low = 5e8;
    int high = 5e8;
    for(int i = 0; i < n; i++) {
      if(i < j && sz[i] < sz[j]) low = min(low, co[i]);
      if(i > j && sz[i] > sz[j]) high = min(high, co[i]);
    }
    ret = min(ret, low + high + co[j]);
  }
  if(ret == 5e8) ret = -1;
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}