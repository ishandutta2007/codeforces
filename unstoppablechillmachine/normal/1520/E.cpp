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
    string s;
    cin >> s;
    int cnt = 0;
    for (auto it : s) {
      cnt += (it == '*');
    }
    int pos = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (s[i] == '*');
      if (sum == (cnt + 1) / 2) {
        pos = i;
        break;
      }
    }
    int ans = 0;
    sum = 0;
    for (int i = 0; i <= pos; i++) {
      if (s[i] == '*') {
        sum++;
      }
      else {
        ans += sum;
      }
    }
    sum = 0;
    for (int i = n - 1; i > pos; i--) {
      if (s[i] == '*') {
        sum++;
      }
      else {
        ans += sum;
      } 
    }
    cout << ans << '\n';
  }
}