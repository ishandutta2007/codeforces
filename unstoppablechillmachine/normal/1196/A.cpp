#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> arr = {a, b, c};
    sort(all(arr));
    if (arr[1] - arr[0] >= arr.back()) {
      cout << arr[0] + arr.back() << '\n';
    }
    else {
      cout << arr[1] + (arr.back() - (arr[1] - arr[0])) / 2 << '\n';
    }
  }  
}