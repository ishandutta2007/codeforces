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
  	int n, d;
  	cin >> n >> d;
  	vector<int> a(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  	}
  	for (int i = 2; i <= n; i++) {
  		while (a[i] > 0 && d >= i - 1) {
  			a[i]--;
  			a[1]++;
  			d -= i - 1;
  		}
  	}
  	cout << a[1] << '\n';
  }
}