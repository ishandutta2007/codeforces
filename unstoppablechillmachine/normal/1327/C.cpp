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
	int n, m;
  cin >> n >> m;
  vector<char> rez;
  for (int i = 1; i < m; i++) {
    rez.pb('L');
  }  
  for (int i = 1; i < n; i++) {
    rez.pb('U');
  }
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      for (int j = 1; j < m; j++) {
        rez.pb('R');
      }
    }
    else {
      for (int j = 1; j < m; j++) {
        rez.pb('L');
      }
    }
    if (i < n) {
      rez.pb('D');
    }
  }
  cout << SZ(rez) << '\n';
  for (auto it : rez) {
    cout << it;
  }
  cout << '\n';
}