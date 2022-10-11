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

int n, m;
ll a[100005];
ll b[100005];
int extra[100005];

void die() {
  cout << "-1\n";
  exit(0);
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    extra[i] = m-1;
  }
  for(int i = 0; i < m; i++) cin >> b[i];
  sort(a, a+n);
  sort(b, b+m);
  if(a[n-1] > b[0]) die();
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ret += m * a[i];
  }
  int idx = n-1;
  for(int i = m-1; i >= 0; i--) {
    if(b[i] == a[idx]) continue;
    while(extra[idx] == 0) idx--;
    if(b[i] != a[idx]) extra[idx]--;
    ret += b[i] - a[idx];
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}