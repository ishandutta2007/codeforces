#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t, a, b, d;
	cin >> t;
	while (t--) {
		cin >> a >> b >> d;
		if (a > b) swap(a, b);
		cout << (1ll * a * (d + 1) < b ? "NO\n" : "YES\n");
	}
	
	return 0;
}