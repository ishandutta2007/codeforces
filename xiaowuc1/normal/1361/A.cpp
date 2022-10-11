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
typedef vector<vector<ll>> matrix;

void die() {
  cout << "-1\n";
  exit(0);
}

vector<int> edges[500005];
int want[500005];
bool seen[500005];
int id[500005];
void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  vector<pii> order;
  for(int i = 1; i <= n; i++) {
    cin >> want[i];
    order.emplace_back(want[i], i);
  }
  sort(all(order));
  int now = 0;
  for(pii out: order) {
    now++;
    for(int out2: edges[out.second]) {
      if(seen[out2]) id[want[out2]] = now;
    }
    bool good = true;
    for(int a = 1; a < out.first && good; a++) {
      good &= id[a] == now;
    }
    good &= id[out.first] != now;
    if(!good) die();
    seen[out.second] = true;
  }
  for(int i = 0; i < sz(order); i++) {
    cout << order[i].second << " \n"[i == sz(order)-1];
  }
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}