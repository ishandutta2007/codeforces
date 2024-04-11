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
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void die() {
  cout << "NO\n";
  exit(0);
}

void solve() {
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  vector<char> ret;
  int last = 0;
  int amt = 0;
  while(a || b) {
    if(last == 1 && amt == k) {
      if(b == 0) die();
      last = 2;
      amt = 1;
      ret.push_back('B');
      b--;
    }
    else if(last == 2 && amt == k) {
      if(a == 0) die();
      last = 1;
      amt = 1;
      ret.push_back('G');
      a--;
    }
    else if(a > b) {
      if(last == 1) amt++;
      else {
        last = 1;
        amt = 1;
      }
      ret.push_back('G');
      a--; 
    }
    else {
      if(last == 2) amt++;
      else {
        last = 2;
        amt = 1;
      }
      ret.push_back('B');
      b--; 
    }
  }
  for(auto out: ret) cout << out; cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}