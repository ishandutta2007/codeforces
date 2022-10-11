#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

void solve() {
  int r, b, y;
  cin >> y >> b >> r;
  int ret = 0;
  for(int rr = 3; true; rr++) {
    if(rr <= r && rr-1 <= b && rr-2 <= y) {
      ret = 3*rr-3;
    }
    else {
      break;
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}