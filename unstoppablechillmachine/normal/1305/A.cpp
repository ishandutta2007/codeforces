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

int cnt0[1010][1010], cnt1[1010][1010], al[1010];

int b_pow(int a, int b, int mod) {
  if (b == 0) {
    return 1 % mod;
  }
  if (b & 1) {
    return (a * b_pow(a, b - 1, mod)) % mod;
  }
  return b_pow((a * a) % mod, b >> 1, mod);
}

mt19937 rnd(time(0));

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
    for (auto &it : a) {
      cin >> it;
    }
    vector<int> b(n);
    for (auto &it : b) {
      cin >> it;
    }
    sort(all(a));
    sort(all(b));
    for (auto it : a) {
      cout << it << ' ';
    }
    cout << '\n';
    for (auto it : b) {
      cout << it << ' ';
    }
    cout << '\n';
  }
}