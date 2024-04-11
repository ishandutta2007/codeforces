#include"bits/stdc++.h"
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(k!=2&&k!=3||n==4&&k==2||n<=3)puts("-1");
	else if(k==2){printf("%d\n",n-1);for(int i=1;i<n;i++)printf("%d %d\n",i,i+1);}
	else if(k==3){
		printf("%d\n",(n-2)*(n-1)/2);
		for(int i=1;i<4;i++)printf("%d %d\n",i,i+1);
		for(int i=5;i<=n;i++)for(int j=2;j<i;j++)printf("%d %d\n",j,i);
	}
	return 0;
}