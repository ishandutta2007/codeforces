#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=300005;
int n,k;
long long ans,sum,now;
long long h[maxn],tot[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&h[i]);
	for(int i=n;i>=1;i--){
		int p=max(1,i-k+1),l=i-p+1;
		h[i]-=sum;
		long long c=(h[i]+l-1)/l;
		if(c>0)
			ans+=c,now+=c,sum+=1ll*l*c,tot[p]+=c;
		sum-=now,now-=tot[i];
	}
	printf("%lld\n",ans);
	return 0;
}