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

int n, k;
int l[100005];
int maxPref[100005];
int maxSuff[100005];
void solve() {
  cin >> n >> k;
  for(int i = 0; i < k; i++) cin >> l[i];
  for(int i = 1; i <= n; i++) maxPref[i] = k;
  for(int i = 1; i <= n; i++) maxSuff[i] = k;

  for(int i = 0; i < k; i++) {
    maxPref[l[i]] = min(maxPref[l[i]], i);
    maxSuff[l[k-1-i]] = min(maxSuff[l[k-1-i]], i);
  }
  ll ret = 0;
  // (a, a)
  for(int i = 1; i <= n; i++) {
    if(maxPref[i] == k) ret++;
  }
  // (a, a-1) or (a, a+1)
  for(int i = 1; i <= n; i++) {
    if(i-1 >= 1 && maxPref[i] + maxSuff[i-1] >= k) {
      ret++;
    }
    if(i+1 <= n && maxPref[i] + maxSuff[i+1] >= k) {
      ret++;
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}