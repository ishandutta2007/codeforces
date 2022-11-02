#include <bits/stdc++.h>
using namespace std;
int n,f[1010],vis[1010];
int tot,ans[1010];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&f[i]);
	for (int i=1;i<=n;i++) {
		memset(vis,0,sizeof(vis));
		int x=i;
		while (!vis[x]) vis[x]=1,x=f[x];
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}