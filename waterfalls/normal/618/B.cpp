#include <bits/stdc++.h>
using namespace std;

int n;
int a[51][51];
int ans[51];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int ok = 1;
			for (int k=1;k<=n;k++) {
				if (k!=j && !ans[k] && a[j][k]!=i) ok = 0;
			}
			if (ok) {
				ans[j] = i;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}