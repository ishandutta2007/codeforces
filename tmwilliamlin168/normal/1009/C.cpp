#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	long long ans=0;
	while(m--) {
		int x, d;
		cin >> x >> d;
		if(d>0)
			ans+=d*(n-1)*n+x*2*n;
		else
			ans+=(n/2)*((n+1)/2)*d*2+x*2*n;
	}
	cout << fixed << setprecision(9) << ans/2.0/n;
}