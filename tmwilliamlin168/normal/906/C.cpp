#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int *friends = new int[n](), *dp1 = new int[1<<n], *dp2 = new int[1<<n], *dp3 = new int[1<<n];
	memset(dp1, 69, 4*(1<<n));
	for(int i=0; i<n; ++i)
		friends[i]=1<<i;
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		friends[u]|=1<<v;
		friends[v]|=1<<u;
	}
	for(int i=1; i<1<<n; ++i) {
		bool ok=1;
		for(int j=0; j<n; ++j) {
			if((i&(1<<j))&&(friends[j]&i)!=i) {
				ok=0;
				break;
			}
		}
		if(ok)
			dp1[i]=0;
	}
	for(int i=1; i<1<<n; ++i) {
		for(int j=0; j<n; ++j) {
			if((i&(1<<j))&&dp1[i]+1<dp1[i|friends[j]]) {
				dp1[i|friends[j]]=dp1[i]+1;
				dp2[i|friends[j]]=j+1;
				dp3[i|friends[j]]=i;
			}
		}
	}
	cout << dp1[(1<<n)-1] << "\n";
	for(int i=0, j=(1<<n)-1; i<dp1[(1<<n)-1]; ++i, j=dp3[j])
		cout << dp2[j] << " ";
}