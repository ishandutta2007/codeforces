#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int t;
	cin >> t;
	for(int qq = 1; qq <= t; qq++) {
		int n, m;
		cin >> n >> m;
		int spaces = n - m;
		//spaces % m: spaces/m+1 choose 2
		//m - spaces % m: spaces/m choose 2
		LL ans = n * (n + 1ll) / 2;
		m++;
		if(m == 0) {
		}else {
			ans -= (LL)spaces % m * (spaces / m + 1ll) * (spaces / m + 2) / 2;
			ans -= (LL)(m - spaces % m) * (spaces / m) * (spaces / m + 1ll) / 2;
		}
		cout << ans << endl;
	}
}