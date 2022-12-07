#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n, t[30111];

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n)
			cin >> t[i];
		ll s = 0;
		bool ans = 1;
		per(i, 0, n - 1) {
			if (t[i] < s)
				ans = 0;
			s += max(0, t[i] - t[i + 1]);
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
	return 0;
}