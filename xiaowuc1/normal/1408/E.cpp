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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<double>> matrix;

int par[100005];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
void merge(int x, int y) {
  par[find(x)] = find(y);
}

ll acost[100005];
ll bcost[100005];
int n, m;

int lastpar[100005];

void solve() { 
  cin >> m >> n;
  for(int i = 0; i < m; i++) cin >> bcost[i];
  for(int i = 0; i < n; i++) cin >> acost[i];
  memset(lastpar, -1, sizeof(lastpar));
  vector<pair<ll, pii>> events; // <cost, <set index, other index>>
  for(int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x--;
      events.eb(bcost[i] + acost[x], pii(i, x));
    }
  }
  for(int i = 1; i <= 100000; i++) par[i] = i;
  sort(all(events));
  reverse(all(events));
  ll ret = 0;
  for(auto event: events) {
    int former = lastpar[event.s.f];
    int currv = event.s.s;
    if(former < 0) {
      lastpar[event.s.f] = find(currv);
    }
    else {
      // if they are the same, remove
      if(find(former) == find(currv)) {
        ret += event.f;
      }
      else {
        merge(former, currv);
      }
    }
  }
  cout << ret << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}