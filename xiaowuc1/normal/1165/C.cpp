#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  string s;
  vector<char> ret;
  cin >> s;
  int i = 0;
  while(i < s.size()) {
    int j = i+1;
    while(j < s.size() && s[i] == s[j]) j++;
    if(j == s.size()) break;
    ret.push_back(s[i]);
    ret.push_back(s[j]);
    i = j+1;
  }
  cout << (int)s.size() - (int)ret.size() << "\n";
  for(char out: ret) cout << out;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}