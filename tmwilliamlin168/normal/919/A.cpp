#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	long double ans=1e9;
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		ans=min((long double)m*a/b, ans);
	}
	cout << fixed << setprecision(9) << ans;
}