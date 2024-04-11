#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int n, x, a;
long long ans;

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> a, v.push_back(a);
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    ans += upper_bound(v.begin(), v.end(), x ^ v[i]) - lower_bound(v.begin(), v.end(), x ^ v[i]);
  }
  if (x == 0) ans -= n;
  ans /= 2;
  cout << ans << '\n';
}