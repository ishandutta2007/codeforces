#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int n, m, k;
string a, b;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> a >> b;
	n = a.size();
	m = b.size();
	
	rep(i, 1, m - 1)
		k ^= (b[i] != b[i - 1]);
		
	int x = 1;
	rep(i, 0, m - 1)
		x ^= (a[i] != b[i]);
		
	int ans = x;
	rep(i, m, n - 1) {
		x ^= (a[i - m] != b[0]);
		x ^= (a[i] != b[m - 1]);
		x ^= k;	
		ans += x;
	}
	cout << ans << "\n";
	return 0;
}