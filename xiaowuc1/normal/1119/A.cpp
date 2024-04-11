#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n;
int l[300005];
void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  int ret = 0;
  for(int i = 1; i < n; i++) {
    if(l[i] != l[0]) ret = max(ret, i);
  }
  for(int i = n-2; i >= 0; i--) {
    if(l[i] != l[n-1]) ret = max(ret, n-1-i);
  }
  cout << ret << endl;
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