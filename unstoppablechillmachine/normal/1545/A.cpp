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

const int MX = 1e5 + 10;
int cnt[2][MX];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < MX; i++) {
      cnt[0][i] = cnt[1][i] = 0;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[i % 2][a[i]]++;
    }
    sort(all(a));
    for (int i = 0; i < n; i++) {
      cnt[i % 2][a[i]]--;
    }
    bool good = true;
    for (int i = 0; i < MX; i++) {
      if (cnt[0][i] != 0 || cnt[1][i] != 0) {
        good = false;
        break;
      }
    }
    cout << (good ? "YES" : "NO") << '\n'; 
  }
}