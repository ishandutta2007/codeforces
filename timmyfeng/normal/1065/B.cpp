#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	int mn = max(0LL, n - m * 2);
	int cnt = 0;
	while ((ll)cnt * (cnt - 1) / 2 < m) {
		++cnt;
	}
	cout << mn << ' ' << n - cnt << '\n';
}