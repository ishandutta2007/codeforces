#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	scanf("%lld",&n);
    long long l=1,r=1e7+10,mid,ans=0,tot=0;
	while(l<=r){
		mid=(l+r)>>1;
        printf("? %lld\n",mid);
        fflush(stdout);
        long long x;
        scanf("%lld",&x);
		x==1?tot=mid,r=mid-1:l=mid+1;
	}
	ans=tot;
	for(long long i=2;i<=n;i++){
		long long res=(tot-1)/i;
        printf("? %lld\n",res);
        fflush(stdout);
        long long x;
        scanf("%lld",&x);
		if(!x)break;
		ans=min(ans,x*res);
	}
    printf("! %lld\n",ans);
	return 0;
}