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

int l[100005];
void solve() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  int lhs = abs(b-a);
  int rhs = 1e9;
  for(int i = 0; i < n; i++) cin >> l[i];
  while(lhs < rhs) {
    int mid = (lhs+rhs)/2;
    set<int> s;
    s.insert(a);
    s.insert(b);
    bool good = true;
    for(int i = 0; good && i < n; i++) {
      while(sz(s) && l[i] - *s.begin() > mid) s.erase(s.begin());
      while(sz(s) && *s.rbegin() - l[i] > mid) s.erase(*s.rbegin());
      if(sz(s)) s.insert(l[i]);
      else good = false;
    }
    if(good) rhs = mid;
    else lhs = mid+1;
  }
  cout << lhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}