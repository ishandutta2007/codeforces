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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

// NO SAD

int nextOne[210000];

void realsolve() {
  string s;
  cin >> s;
  nextOne[s.size()] = s.size();
  for(int i = s.size()-1; i >= 0; i--) {
    nextOne[i] = nextOne[i+1];
    if(s[i] == '1') nextOne[i] = i;
  }
  int ret = 0;
  for(int i = 0; i < s.size(); i++) {
    int rhs = nextOne[i];
    if(rhs == s.size()) break;
    int currVal = 1;
    while(true) {
      int want = rhs-i+1;
      if(want == currVal) {
        ret++;
      }
      if(rhs >= s.size()-1) break;
      currVal *= 2;
      currVal += s[++rhs] - '0';
      if(currVal > s.size()) break;
    }
  }
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}