#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

void solve() {
  int ang;
  cin >> ang;
  for(int n = 3; true; n++) {
    for(int a = 1; a <= n-2; a++) {
      ll num = 180 * a;
      if(num%n) continue;
      num /= n;
      if(num == ang) {
        cout << n << endl;
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  int t;
  cin >> t;
  while(t--) solve();
}