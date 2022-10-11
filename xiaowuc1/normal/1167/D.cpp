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

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int d = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(') {
      if(d%2 == 0) cout << 0;
      else cout << 1;
      d++;
    }
    else {
      if(d%2 == 1) cout << 0;
      else cout << 1;
      d--;
    }
  }
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