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
typedef bitset<150> bs;

const int MAX_DEPTH = 30;
const int MAX_N = 150;
bs can[MAX_N][MAX_DEPTH];

typedef pair<int, pii> event;
int n;

bs iterate(bs curr, int d) {
  bs ret;
  for(int i = 0; i < n; i++) if(curr[i]) ret |= can[i][d];
  return ret;
}

void win(int currt) {
  cout << currt << "\n";
  exit(0);
}

void rebuild() {
  for(int d = 1; d < MAX_DEPTH; d++) {
    for(int i = 0; i < n; i++) can[i][d] = iterate(can[i][d-1], d-1);
  }
}

void solve() {
  int m;
  cin >> n >> m;
  vector<event> events(m);
  for(int i = 0; i < m; i++) {
    cin >> events[i].second.first >> events[i].second.second >> events[i].first;
    events[i].second.first--;
    events[i].second.second--;
  }
  sort(all(events));
  int currt = 0;
  bs curr;
  curr.set(0);
  for(auto out: events) {
    int need = out.first - currt;
    for(int qq = 0; qq <= n && need > 0; qq++, need--) {
      curr = iterate(curr, 0);
      currt++;
      if(curr[n-1]) {
        win(currt);
      }
    }
    for(int d = MAX_DEPTH-1; need && d >= 0; d--) {
      if((1<<d) <= need) {
        curr = iterate(curr, d);
        currt += (1 << d);
        need -= (1<<d);
      }
    }
    can[out.second.first][0].set(out.second.second);
    rebuild();
  }
  for(int qq = 0; qq <= n; qq++) {
    curr = iterate(curr, 0);
    currt++;
    if(curr[n-1]) win(currt);
  }
  cout << "Impossible\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}