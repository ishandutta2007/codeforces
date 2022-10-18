#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,a[N];

ll s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		bool flg=0;
		ll ans=-1e18;
		for(int i=0;i<=n;i++){
			ll b=1ll*a[n]*s[i]+1ll*a[1]*(s[n]-s[i]),k=s[i]+1ll*i*a[n]+(s[n]-s[i])+1ll*(n-i)*a[1];
			if(!i){
				b-=1ll*a[1]*a[1],k-=a[1]+a[1];
				if(k>0){
					flg=1;
					break;
				}
				ans=std::max(ans,k*(-a[i+1])+b);
			}
			else if(i==n){
				b-=1ll*a[n]*a[n],k-=a[n]+a[n];
				if(k<0){
					flg=1;
					break;
				}
				ans=std::max(ans,k*(-a[i])+b);
			}
			else{
				b-=1ll*a[1]*a[n],k-=a[1]+a[n];
				ans=std::max(ans,std::max(k*(-a[i])+b,k*(-a[i+1])+b));
			}
		}
		if(flg)
			puts("INF");
		else
			printf("%lld\n",ans);
	}
}