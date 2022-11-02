#include <bits/stdc++.h>
using namespace std;

int n,k;
int ans[513][513];

int main() {
	scanf("%d%d",&n,&k);
	int on = 1;
	for (int j=1;j<k;j++) {
		for (int i=1;i<=n;i++) {
			ans[i][j] = on++;
		}
	}
	int res = 0;
	for (int i=1;i<=n;i++) {
		for (int j=k;j<=n;j++) {
			if (j==k) res+=on;
			ans[i][j] = on++;
		}
	}
	printf("%d\n",res);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}

	return 0;
}