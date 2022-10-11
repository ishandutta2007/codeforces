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
typedef pair<pii, bool> piib;
typedef pair<double, double> pdd;
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;

pll l[7000];
bool alwaysCan[7000];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i].first;
  }
  for(int i = 0; i < n; i++) {
    cin >> l[i].second;
  }
  sort(l, l+n);
  ll force = 0;
  for(int i = 1; i < n; i++) {
    if(l[i].first == l[i-1].first) {
      alwaysCan[i] = true;
      alwaysCan[i-1] = true;
    }
  }
  ll ret = 0;
  set<ll> cover;
  for(int i = 0; i < n; i++) {
    if(alwaysCan[i]) {
      ret += l[i].second;
      cover.insert(l[i].first);
    }
  }
  for(int i = 0; i < n; i++) {
    if(alwaysCan[i]) continue;
    bool covered = false;
    for(ll out: cover) {
      covered |= (out & l[i].first) == l[i].first;
    }
    if(covered) ret += l[i].second;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}