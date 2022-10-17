#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

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
    string rez;
    reverse(all(s));
    while (!s.empty() && s.back() == '0') {
      rez.pb('0');
      s.pop_back();
    }
    reverse(all(s));
    int need = 1, cnt = 0;
    for (auto it : s) {
      if (it - '0' == need) {
        cnt++;
        need ^= 1;
      }
    }
    if (cnt >= 2) {
      rez.pb('0');
    }
    while (!s.empty() &&  s.back() == '1') {
      s.pop_back();
      rez.pb('1');
    }
    cout << rez << '\n';
  }
}