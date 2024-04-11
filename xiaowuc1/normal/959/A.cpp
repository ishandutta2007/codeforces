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

void solve() {
  ll n;
  cin >> n;
  for(int i = 0; true; i++) {
    if(i % 2 == 0) {
      if(n <= 1) {
        cout << "Ehab\n";
        return;
      }
      n %= 2;
    }
    else {
      if(n == 0) {
        cout << "Mahmoud\n";
        return;
      }
      if(n%2==0) n = 1;
      else n = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}