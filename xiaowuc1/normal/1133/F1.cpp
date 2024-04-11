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
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int par[1000000];
int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}
bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return false;
  par[a] = b;
  return true;
}

int deg[1000000];
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pii> e;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e.emplace_back(a, b);
    deg[a]++;
    deg[b]++;
  } 
  for(int i = 1; i <= n; i++) par[i] = i;
  int best = 1;
  for(int i = 2; i <= n; i++) {
    if(deg[i] > deg[best]) best = i;
  }
  for(auto out: e) {
    if(out.f == best || out.s == best) {
      if(merge(out.f, out.s)) cout << out.f << " " << out.s << "\n";
    }
  }
  for(auto out: e) {
      if(merge(out.f, out.s)) cout << out.f << " " << out.s << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}