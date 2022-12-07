#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;
int t, n;
int main() { 
	cin >> t;
	while (t--) {
		cin >> n;
		ll s = 0, a;
		rep(i, 0, n) {
			cin >> a;
			s += a;
		}
		cout << (s % n) * (n - s % n) << "\n";
	}
	return 0;
}