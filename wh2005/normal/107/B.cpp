#include<bits/stdc++.h>
using namespace std;
int n,m,h,a[1009],sum;
int main(){
	scanf("%d%d%d",&n,&m,&h);sum=0;
	for(int i=1;i<=m;i++) scanf("%d",&a[i]),sum+=a[i];
	if(sum<n){
		printf("-1\n");
		return 0;
	}
	if(a[h]==1){
		printf("0\n");
		return 0;
	}
	if(sum==n){
		printf("1\n");
		return 0;
	}
	double ans=1.0;
	for(int i=1;i<n;i++)
		ans=(ans*((sum-a[h]-i+1)*1.0)/((sum-i)*1.0));
	ans=1-ans;
	printf("%lf\n",ans);
	return 0;
}