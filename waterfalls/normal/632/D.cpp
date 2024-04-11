#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000013];
int has[1000013];
int ans[1000013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]<=m) has[a[i]]+=1;
	}
	for (int i=1;i<=m;i++) {
		for (int j=i;j<=m;j+=i) ans[j]+=has[i];
	}
	int best = -1;
	int which = 0;
	for (int i=1;i<=m;i++) {
		if (ans[i]>best) {
			best = ans[i];
			which = i;
		}
	}
	printf("%d %d\n",which,ans[which]);
	for (int i=1;i<=n;i++) if (which%a[i]==0) printf("%d ",i);
	printf("\n");

	return 0;
}