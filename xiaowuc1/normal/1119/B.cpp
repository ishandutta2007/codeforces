#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, h;
int l[1005];

bool can(int k) {
  vector<int> v;
  for(int i = 0; i < k; i++) {
    v.push_back(l[i]);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ll tot = 0;
  for(int i = 0; i < v.size(); i += 2) tot += v[i];
  return tot <= h;
}

void solve() {
  cin >> n >> h;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int lhs = 0;
  int rhs = n;
  while(lhs != rhs) {
    int mid = (lhs+rhs+1)/2;
    if(can(mid)) lhs = mid;
    else rhs = mid-1;
  }
  cout << lhs << endl;
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