#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 998244353;
const int N = 1e6+9;
int T,n;
ll a[N];

ll p[N];
ll val(int i){
	if(a[i]%(p[i]+1)==0) return a[i]/(p[i]+1);
	return a[i]/(p[i]+1)+1;
}
ll mval(int i){
	return a[i]/(p[i]+1);
}
ll sum;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) p[i]=0;
		sum=0;
		ll ans=0;
		for(int r=1;r<=n;r++){
			ll lst=a[r];
			for(int l=r-1;l>=1;l--){
				if(val(l)>lst){
					(sum+=mod-p[l]*l%mod)%=mod;
					p[l]=a[l]/lst-1;
					if(p[l]<0) p[l]=0;
					if(val(l)>lst) p[l]++;
					if(val(l)>lst) p[l]++;
					lst=mval(l);
					(sum+=p[l]*l%mod)%=mod;		
				}
				else break;
			}
			(ans+=sum)%=mod;
		}	
		printf("%lld\n",ans);
	}
	return 0;
}
/*
 




 O(n) 

 
*/