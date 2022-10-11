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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

int lowest[10000001];
pii best[10000001][2];
int seen[10000001];
void solve() {
  for(int x = 1; x <= 1e7; x++) lowest[x] = x;
  for(int x = 2; x <= 1e7; x++) {
    best[x][0] = {1e9, 1};
    best[x][1] = {1e9, 1};
    if(lowest[x] != x) continue;
    for(int y = x; y <= 1e7; y += x) {
      lowest[y] = x;
    }
  }
  best[1][0] = {1e9, 1};
  best[1][1] = {1e9, 1};
  int n;
  cin >> n;
  for(int qqq = 1; qqq <= n; qqq++) {
    int x;
    cin >> x;
    if(++seen[x] > 2) continue;
    pii force = {x, qqq};
    vector<int> facs;
    facs.push_back(1);
    while(x > 1) {
      int amt = 0;
      int cand = lowest[x];
      while(x%cand == 0) {
        x /= cand;
        amt++;
      }
      int thresh = sz(facs);
      for(int i = 0; i < thresh; i++) {
        int curr = facs[i];
        for(int a = 1; a <= amt; a++) {
          curr *= cand;
          facs.push_back(curr);
        }
      }
    }
    for(int out: facs) {
      if(force < best[out][0]) {
        best[out][1] = best[out][0];
        best[out][0] = force;
      }
      else if(force < best[out][1]) {
        best[out][1] = force;
      }
    }
  }
  ll ret = 1e18;
  pii ans = {0, 0};
  for(int x = 1; x <= 1e7; x++) {
    if(best[x][1].first == 1e9) continue;
    ll cand = best[x][0].first * (ll)best[x][1].first;
    cand /= __gcd(best[x][0].first, best[x][1].first);
    if(cand < ret) {
      ret = cand;
      ans = {best[x][0].second, best[x][1].second};
    }
  }
  if(ans.first > ans.second) swap(ans.first, ans.second);
  cout << ans.first << " " << ans.second << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}