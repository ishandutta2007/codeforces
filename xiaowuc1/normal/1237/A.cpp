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
#include <unordered_map>
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
typedef pair<int, bool> state;
typedef pair<double, pii> event;

int l[100000];
int ret[100000];
int n;
void solve() {
  cin >> n;
  int tot = 0;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    ret[i] = l[i] / 2;
    tot += ret[i];
  }
  for(int i = 0; i < n; i++) {
    if(tot < 0) {
      int cand = ret[i] + 1;
      if(abs(l[i] - 2 * cand) <= 1) {
        ret[i]++;
        tot++;
      }
    }
    else if(tot > 0) {
      int cand = ret[i] - 1;
      if(abs(l[i] - 2 * cand) <= 1) {
        ret[i]--;
        tot--;
      }
    }
  }
  assert(tot == 0);
  for(int i = 0; i < n; i++) cout << ret[i] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}