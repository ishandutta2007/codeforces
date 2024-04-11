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
	int x = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    cout << b + x << ' ';
    x = max(x, b + x);
  }
  cout << '\n';
}