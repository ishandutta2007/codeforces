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
typedef pair<int, pii> state;

bool piisort(pii a, pii b) {
  return a.second > b.second;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pii> v(n);
  map<int, int> amt;
  map<int, int> score;
  for(int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(all(v), piisort);
  int ret = 0;
  map<int, int> forceScore;
  for(pii out: v) {
    amt[out.first]++;
    score[out.first] += out.second;
    if(score[out.first] > 0) {
      forceScore[amt[out.first]] += score[out.first];
      ret = max(ret, forceScore[amt[out.first]]);
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}