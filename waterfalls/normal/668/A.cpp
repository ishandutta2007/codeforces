#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int a[10013], b[10013], c[10013], d[10013];
int ans[113][113];

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<q;i++) {
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]==3) scanf("%d%d",&c[i],&d[i]);
		b[i]-=1;
		c[i]-=1;
	}
	for (int i=q-1;i>=0;i--) {
		if (a[i]==1) {
			int tmp = ans[b[i]][m-1];
			for (int j=m-1;j>0;j--) ans[b[i]][j] = ans[b[i]][j-1];
			ans[b[i]][0] = tmp;
		} else if (a[i]==2) {
			int tmp = ans[n-1][b[i]];
			for (int j=n-1;j>0;j--) ans[j][b[i]] = ans[j-1][b[i]];
			ans[0][b[i]] = tmp;
		} else {
			ans[b[i]][c[i]] = d[i];
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}

	return 0;
}