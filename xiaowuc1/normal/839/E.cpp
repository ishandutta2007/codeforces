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

#include <unordered_map>

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
typedef bitset<40> bs;

bs g[40];
int n;
int ret;

vector<pii> order;

void dfs(int idx, bs use, bs cand) {
  if((use|cand).count() <= ret) return;
  ret = max(ret, (int)use.count());
  if(idx == sz(order)) return;
  if(cand[order[idx].second]) {
    use.flip(order[idx].second);
    dfs(idx+1, use, cand & g[order[idx].second]);
    use.flip(order[idx].second);
  }
  cand.flip(order[idx].second);
  dfs(idx+1, use, cand);
}

void solve() {
  int k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int t = 0;
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      t += x;
      if(x) g[i].set(j);
    }
    order.push_back({t, i});
  }
  sort(all(order));
  reverse(all(order));
  mt19937 g1(std::chrono::system_clock::now().time_since_epoch().count());
  shuffle(all(order), g1);
  bs cand;
  for(int i = 0; i < n; i++) cand.set(i);
  bs empt;
  dfs(0, empt, cand);
  cout << fixed << setprecision(12) << k * k * (1 - 1.0 / ret) / 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}