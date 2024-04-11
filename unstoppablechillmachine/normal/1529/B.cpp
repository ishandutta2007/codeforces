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
 
const int inf = 1e9 + 10; 

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
    int answer = 0, mn = inf;
    for (auto& x : a) {
      cin >> x;
      if (x <= 0) {
        answer++;
      } else {
        mn = min(mn, x);
      }
    }
    if (mn < inf) {
      sort(a.rbegin(), a.rend());
      int prv = mn, sum = 1;
      for (int i = 0; i < n; i++) {
        if (a[i] <= 0 && prv - a[i] >= mn) {
          prv = a[i];
          sum++;
        }
      }  
      answer = max(answer, sum);
    }
    cout << answer << '\n';
  }
}