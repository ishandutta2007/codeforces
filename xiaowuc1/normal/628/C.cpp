#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int maxOp = 0;
  for(int i = 0; i < n; i++) {
    maxOp += max('z' - s[i], s[i] - 'a');
  }
  if(maxOp < k) {
    cout << -1 << endl;
    return;
  }
  for(int i = 0; i < n; i++) {
    char choose = 0;
    int t = -1;
    for(char ch = 'a'; ch <= 'z'; ch++) {
      int error = abs(ch - s[i]);
      if(error > t && error <= k) {
        choose = ch;
        t = error;
      }
    }
    k -= t;
    cout << choose;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}