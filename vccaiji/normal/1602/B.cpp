#include<bits/stdc++.h>
using namespace std;
int a[2100];
int ans[4100][2100];
int o[2100]={};
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n,q;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) ans[0][i]=a[i];
		for(int i=1;i<=2*n;i++){
			for(int j=0;j<=n;j++) o[j]=0;
			for(int j=1;j<=n;j++) o[ans[i-1][j]]++;
			for(int j=1;j<=n;j++) ans[i][j]=o[ans[i-1][j]];
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			int x,k;
			scanf("%d%d",&x,&k);
			printf("%d\n",ans[min(2*n,k)][x]);
		}
	}
	return 0;
}