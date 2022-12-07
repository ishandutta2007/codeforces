#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n, a, b;

int main() { 
	cin >> T;
	while (T--) {
		cin >> n >> a >> b;
		bool res = 0;
		ll p = 1;
		while (p <= n) {
			res |= (n - p) % b == 0;
			p *= a;
			if (a == 1)
				break;
		}
		cout << (res ? "YES\n" : "NO\n");
	}
	return 0;
}