#include <bits/stdc++.h>
using namespace std;

int ans[33][33][53];

int main() {
	for (int i=0;i<33;i++) for (int j=0;j<33;j++) {
		for (int k=0;k<53;k++) {
			ans[i][j][k] = 1e9;
			if (k==0 || i*j==k) ans[i][j][k] = 0;
			for (int u=0;u<=k;u++) {
				for (int a=1;a<i;a++) {
					ans[i][j][k] = min(ans[i][j][k],ans[a][j][u]+ans[i-a][j][k-u]+j*j);
				}
				for (int a=1;a<j;a++) {
					ans[i][j][k] = min(ans[i][j][k],ans[i][a][u]+ans[i][j-a][k-u]+i*i);
				}
			}
		}
	}
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",ans[n][m][k]);
	}

	return 0;
}