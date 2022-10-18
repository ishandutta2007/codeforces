#include<bits/stdc++.h>
#define ll long long
#define N 5005

int n,a[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		ll res=0,tmp=0;
		for(int j=i-1;j;j--){
			ll x=tmp/a[j]+1;
			res+=x,tmp=x*a[j];
		}
		tmp=0;
		for(int j=i+1;j<=n;j++){
			ll x=tmp/a[j]+1;
			res+=x,tmp=x*a[j];
		}
		ans=std::min(ans,res);
	}
	printf("%lld\n",ans);
}