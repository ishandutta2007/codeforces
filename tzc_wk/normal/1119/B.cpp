#include<bits/stdc++.h>
int n,h,a[1005],i,j;
int main(){
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		std::sort(a+1,a+i+1);
		long long su=0;
		for(j=i;j>0;j-=2)su+=a[j];
		if(su>h)break;
	}
	printf("%d\n",i-1);
	return 0;
}