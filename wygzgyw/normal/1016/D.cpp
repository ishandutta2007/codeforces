#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],ans[110][110],s1,s2;
int main() {
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) s1^=a[i],ans[i][1]=a[i];
	for (int i=1;i<=m;i++) s2^=b[i],ans[1][i]=b[i];
	if (s1!=s2) printf("NO\n");
	else {
		printf("YES\n");
		s1=a[1];
		for (int i=2;i<=m;i++) s1^=b[i];
		ans[1][1]=s1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}