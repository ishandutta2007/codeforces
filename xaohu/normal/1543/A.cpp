#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;
int t;
ll a, b;
int main() { 
	cin >> t;
	while (t--) {
		cin >> a >> b;
		ll c = abs(a - b);
		if (c == 0) {
			cout << 0 << " " << 0 << "\n";
		}
		else {
			cout << c << " " << min(a % c, c - a % c) << "\n";
		}
	}
	return 0;
}