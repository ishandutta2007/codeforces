#include <algorithm>
#include <bitset>
#include <cassert>
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
typedef pair<double, double> pdd;

void solve() {
  string s;
  cin >> s;
  int lhs = 0;
  int rhs = s.size()-1;
  vector<char> lhsV, rhsV;
  while(lhs <= rhs) {
    if(rhs - lhs == 0) {
      lhsV.push_back(s[lhs++]);
      break;
    }
    if(rhs - lhs == 1) {
      if(s[lhs] == s[rhs]) {
        lhsV.push_back(s[lhs++]);
        rhsV.push_back(s[rhs--]);
        break;
      }
      lhsV.push_back(s[lhs++]);
      break;
    }
    if(rhs - lhs == 2) {
      set<char> ss;
      ss.insert(s[lhs]);
      ss.insert(s[lhs+1]);
      ss.insert(s[lhs+2]);
      if(ss.size() == 3) {
        lhsV.push_back(s[lhs++]);
        break;
      }
      assert(s[lhs] == s[rhs]);
      lhsV.push_back(s[lhs++]);
      rhsV.push_back(s[rhs--]);
      break;
    }
    assert(rhs - lhs >= 3);
    if(s[lhs] == s[rhs]) {
      lhsV.push_back(s[lhs]);
      rhsV.push_back(s[rhs]);
      lhs = lhs+1;
      rhs = rhs-1;
      continue;
    }
    if(s[lhs] == s[rhs-1]) {
      lhsV.push_back(s[lhs]);
      rhsV.push_back(s[rhs-1]);
      lhs = lhs+1;
      rhs = rhs-2;
      continue;
    }
    if(s[lhs+1] == s[rhs]) {
      lhsV.push_back(s[lhs+1]);
      rhsV.push_back(s[rhs]);
      lhs = lhs+2;
      rhs = rhs-1;
      continue;
    }
    if(s[lhs+1] == s[rhs-1]) {
      lhsV.push_back(s[lhs+1]);
      rhsV.push_back(s[rhs-1]);
      lhs = lhs+2;
      rhs = rhs-2;
      continue;
    }
    assert(false);
  }
  reverse(rhsV.begin(), rhsV.end());
  for(char out: lhsV) cout << out;
  for(char out: rhsV) cout << out;
  cout << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}