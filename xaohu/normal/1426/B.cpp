#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
typedef long long ll;	
using namespace std;

int T, n, m;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		bool ans = false;
		while (n--) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if (b == c)
				ans = true;
		}
		cout << (m % 2 == 0 && ans ? "YES\n" : "NO\n");
	}
	return 0;
}