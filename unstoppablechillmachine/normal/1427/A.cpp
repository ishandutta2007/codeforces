#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll    

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &it : a) {
      cin >> it;
      sum += it;
    }
    if (sum == 0) {
      cout << "NO\n";
      continue;
    }
    if (sum > 0) {
      sort(a.rbegin(), a.rend());
    }
    else {
      sort(all(a));
    }
    cout << "YES\n";
    for (auto it : a) {
      cout << it << ' ';
    }
    cout << '\n';
  }
}