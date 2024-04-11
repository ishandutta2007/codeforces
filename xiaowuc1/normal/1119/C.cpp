#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int r, c;
int a[505][505];
int b[505][505];
bool flip[505];
void solve() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> a[i][j];
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> b[i][j];
  bool good = true;
  for(int i = 0; i < r; i++) {
    int count = 0;
    for(int j = 0; j < c; j++) {
      if(a[i][j] != b[i][j]) {
        flip[j] ^= true;
        count++;
      }
    }
    if(count % 2) good = false;
  }
  for(int j = 0; j < c; j++) if(flip[j]) good = false;
  if(good) cout << "Yes\n";
  else cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}