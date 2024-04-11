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
  vector<int> v;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  int ret = 0;
  for(int out: v) {
    if(out > ret) {
      ret++;
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