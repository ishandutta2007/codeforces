#include <bits/stdc++.h>
using namespace std;

int n, k, x, i, ans=1<<30;

int main(){
	for(scanf("%d%d",&n,&k),i=0;i<n;i++){
		scanf("%d",&x);
		if(k%x==0) ans=min(ans,k/x);
	}
	printf("%d\n",ans);
	return 0;
}