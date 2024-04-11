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

mt19937 g1;
bool present[200005];
int ret[200005];
void solve() {
  int n;
  cin >> n;
  vector<int> indices;
  for(int i = 1; i <= n; i++) {
    cin >> ret[i];
    present[ret[i]] = true;
    if(ret[i] == 0) indices.push_back(i);
  }
  vector<int> need;
  for(int i = 1; i <= n; i++) {
    if(!present[i]) need.push_back(i);
  }
  while(true) {
    shuffle(all(need), g1);
    bool good = true;
    for(int i = 0; i < sz(indices) && good; i++) {
      good = need[i] != indices[i];
    }
    if(good) {
      for(int i = 0; i < sz(indices); i++) ret[indices[i]] = need[i];
      break;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i) cout << " "; cout << ret[i+1];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}