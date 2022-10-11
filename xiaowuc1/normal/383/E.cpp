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
typedef pair<long double, ll> pdll;

int ret[1<<24];

void solve(int lhs, int rhs) {
  if(lhs == rhs) {
    return;
  }
  int mid = (lhs+rhs)/2;
  int sz = rhs - lhs + 1;
  solve(lhs, mid);
  solve(mid+1, rhs);
  for(int i = lhs + sz/2; i <= rhs; i++) ret[i] += ret[i-sz/2];
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int curr = 0;
    for(int a = 0; a < 3; a++) curr |= 1 << (s[a] - 'a');
    ret[curr]++;
  }
  solve(0, (1<<24)-1);
  ll ans = 0;
  for(int i = 0; i < (1 << 24); i++) {
    ll curr = n - ret[i];
    curr *= curr;
    ans ^= curr;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}