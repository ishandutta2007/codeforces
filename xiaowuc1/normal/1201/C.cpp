#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

ll l[1000005];
void solve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  sort(l, l+n);
  ll lhs = l[n/2];
  ll rhs = 1e10;
  while(lhs < rhs) {
    ll mid = (lhs+rhs+1)/2;
    ll need = 0;
    for(int i = n/2; i < n; i++) {
      need += max(0LL, mid - l[i]);
    }
    if(need <= k) lhs = mid;
    else rhs = mid-1;
  }
  cout << lhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}