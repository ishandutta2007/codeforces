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
    string s;
    int n;
    cin >> n >> s;
    int cnt_zeros = accumulate(all(s), 0ll, [](int result, char c) { 
      return result + (c == '0'); 
    });
    cout << (((cnt_zeros & 1) && cnt_zeros > 1) ? "ALICE" : "BOB") << '\n';  
  }
}