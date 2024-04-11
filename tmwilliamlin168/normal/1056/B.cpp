#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, m, ans=0;
	cin >> n >> m;
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=m; ++j)
			if((i*i+j*j)%m==0)
				ans+=((n-i+m)/m)*((n-j+m)/m);
	cout << ans;
}