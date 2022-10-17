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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> val(k, -1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        if (val[i % k] == -1) {
          val[i % k] = s[i] - '0';
        }
        else if (val[i % k] != s[i] - '0') {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < k; i++) {
      if (val[i] != -1) {
        s[i] = char('0' + val[i]);
      }
      if (s[i] == '0') {
        cnt0++;
      }
      if (s[i] == '1') {
        cnt1++;
      }
    }
    if (max(cnt0, cnt1) > k / 2) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }  
}