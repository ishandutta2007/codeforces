#include <bits/stdc++.h>
using namespace std;

int n, m;
bool c[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		int l, r;
		cin >> l >> r;
		for(int j=l; j<=r; ++j)
			c[j]=1;
	}
	int ans=0;
	for(int i=1; i<=m; ++i)
		ans+=!c[i];
	cout << ans << "\n";
	for(int i=1; i<=m; ++i)
		if(!c[i])
			cout << i << " ";
}