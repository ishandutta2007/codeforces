#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
 
int f(int n) {
	return n * (n - 1) / 2;
}
 
signed main() {
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int cnt = 2;
		while (f(cnt + 1) <= n) {
			cnt++;
		}
		cout << "133";
		for (int i = 0; i < n - f(cnt); i++) {
			cout << 7;
		} 
		for (int i = 0; i < cnt - 2; i++) {
			cout << 3;
		}
		cout << "7\n";
	}
}