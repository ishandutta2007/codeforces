#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
long long n,r,k,a[500005],b[500005],c[500005];
bool check(long long kk){
	ll cnt=0;
	memset(c,0,sizeof c);
	for(ll i=1;i<=n;i++){
		c[i]+=c[i-1];
		if(c[i]+a[i]<kk){
			long long p=kk-c[i]-a[i];
			c[i]+=p;
			c[i+r*2+1]-=p;
			cnt+=p;
			if(cnt>k)return 0;
		}
	}
	return cnt<=k;
}
int main(){
	scanf("%lld%lld%lld",&n,&r,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	for(int i=1;i<=n;i++)a[i]=b[min(n,i+r)]-b[max(0ll,i-r-1)];
	long long l=0,r=1.1e18,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}