#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long h,w,k,x1,x2,x3,x4;
		scanf("%lld%lld",&w,&h);
		long long now;
		scanf("%lld",&k);
		scanf("%lld",&x1);
		for(int i=1;i<k;i++)scanf("%lld",&now);
		x1=now-x1; 
		scanf("%lld",&k);
		scanf("%lld",&x2);
		for(int i=1;i<k;i++)scanf("%lld",&now);
		x2=now-x2; 
		scanf("%lld",&k);
		scanf("%lld",&x3);
		for(int i=1;i<k;i++)scanf("%lld",&now);
		x3=now-x3; 
		scanf("%lld",&k);
		scanf("%lld",&x4);
		for(int i=1;i<k;i++)scanf("%lld",&now);
		x4=now-x4;
		printf("%lld\n",max(max(x1,x2)*h,max(x3,x4)*w));
	}
	return 0;
}