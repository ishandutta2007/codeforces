#include<cstdio>
#include<algorithm>
#define ll long long

ll T;

ll n,k,l1,r1,l2,r2;

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld%lld",&n,&k,&l1,&r1,&l2,&r2);
		ll len1=r1-l1,len2=r2-l2;
		ll len=std::max(r1,r2)-std::min(l1,l2);
		ll t=(len<<1)-len1-len2;
		ll xlen=std::max(std::min(r1,r2)-std::max(l1,l2),0ll);
		ll t0=xlen?0:std::max(l1,l2)-std::min(r1,r2);
		if(1ll*xlen*n>=k){
			puts("0");
			continue;
		}
		k-=xlen*n;
		len-=xlen;
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(k<=len){
				ans+=std::min(t0+k,i>1?2*k:t0+k);
				k=0;
				break;
			}
			ans+=t;
			k-=len;
		}
		ans+=k*2;
		printf("%lld\n",ans);
	}
}