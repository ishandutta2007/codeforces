#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int T, n, a[1 << 20];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		map<int, int> m[2];
		rep(i, 0, n) {
			cin >> a[i];
			m[i % 2][a[i]]++;
		}
		sort(a, a + n);
		bool res = 1;
		rep(i, 0, n) {
			if (--m[i % 2][a[i]] < 0)
				res = 0;
		}
		cout << (res ? "YES\n" : "NO\n");
	}

	return 0;
}