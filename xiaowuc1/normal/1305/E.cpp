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

void die() {
  cout << "-1\n";
  exit(0);
}

/*
3 1
4 2
5 4
6 6
7 9
8 12
9 16
odd n, (n/2)^2
even n, n/2 * (n/2-1)
*/

int maxAmt(int n) {
  if(n%2) {
    return (n/2) * (n/2);
  }
  return (n/2) * (n/2-1);
}

void solve() {
  int n, m;
  cin >> n >> m;
  {
    int can = maxAmt(n);
    if(can < m) die();
  }
  if(m == 0) {
    // be bad
    for(int i = 0; i < n; i++) {
      if(i) cout << " ";
      cout << (int)(1000000000 - n + i);
    }
    cout << "\n";
    return;
  }
  // don't die
  // find the smallest N such that you can reach the end if you're not bad
  vector<int> ret;
  int need = 0;
  while(maxAmt(need) < m) need++;
  assert(need <= n); // ???
  need--;
  // buffer 1 to need
  for(int i = 1; i <= need; i++) {
    ret.push_back(i);
  }
  int numPairsNeed = m - maxAmt(need);
  assert(sz(ret) / 2 >= numPairsNeed); // otherwise impossible
  // find the smallest value that is included exactly that many times
  {
    // validate
    int cand = ret.back()+1;
    while(true) {
      int lhs = 0;
      int rhs = sz(ret)-1;
      int have = 0;
      while(lhs < rhs) {
        if(ret[lhs] + ret[rhs] == cand) {
          lhs++;
          rhs--;
          have++;
        }
        else if(ret[lhs] + ret[rhs] < cand) lhs++;
        else rhs--;
      }
      if(have == numPairsNeed) {
        ret.push_back(cand);
        break;
      }
      cand++;
    }
  }
  // buffer the rest out
  int diff = ret.back() + 1;
  int curr = 1e9;
  while(sz(ret) < n) {
    ret.push_back(curr);
    curr -= diff;
  }
  sort(all(ret));
  // be super paranoid locally
  if(false) {
    int fin = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        for(int k = j+1; k < n; k++) {
          if(ret[i] + ret[j] == ret[k]) fin++;
        }
      }
    }
    assert(fin == m);
  }
  for(int i = 0; i < n; i++) {
    if(i) cout << " "; cout << ret[i];
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}