#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll c[31];

ll solve(int i, int left) {
	if(left<=0)
		return 0;
	if(i<0||left>=(1LL<<(i+1)))
		return (ll)1e18;
	return min(solve(i-1, left), solve(i-1, left-(1<<i))+c[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, L;
	ll ans=0;
	cin >> n >> L;
	for(int i=0; i<n; ++i) {
		cin >> c[i];
		if(i)
			c[i]=min(2*c[i-1], c[i]);
	}
	for(int i=n; i<31; ++i)
		c[i]=2*c[i-1];
	cout << solve(30, L);
}