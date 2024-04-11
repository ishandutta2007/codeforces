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
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  int ret = 0;
  s = s.substr(n - a);
  b = s.size()-1-b;
  for(int i = 0; i < s.size(); i++) {
    if(i == b) {
      if(s[i] != '1') ret++;
    }
    else {
      if(s[i] != '0') ret++;
    }
  }
  cout << ret << endl;
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