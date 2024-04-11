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
    string s2 = s;
    sort(all(s2));
    int answer = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == s2[i]) {
        answer--;
      }
    }
    cout << answer << '\n';
  }
}