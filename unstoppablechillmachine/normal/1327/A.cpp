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

const int N = 1e7 + 10;
int f[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int T;
	cin >> T;
	f[1] = 1;
	for (int i = 2; i <= 1e7; i++) {
		f[i] = f[i - 1] + i * 2 - 1;
	}
	while (T--) {
		int n, k;
		cin >> n >> k;
		if (n % 2 != k % 2 || f[k] > n) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	} 
}