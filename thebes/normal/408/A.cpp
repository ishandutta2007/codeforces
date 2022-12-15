#include <bits/stdc++.h>
using namespace std;

int ans = 1<<30, n, i, k, j, x, len[105];

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&len[i]);
	}
	for(i=1;i<=n;i++){
		x = 0; k = 0;
		for(j=0;j<len[i];j++)
			scanf("%d",&x),k+=x;
		ans=min(ans,k*5+15*len[i]);
	}
	printf("%d\n",ans);
	return 0;
}