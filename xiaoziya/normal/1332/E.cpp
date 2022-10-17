#include<stdio.h>
const int mod=998244353,inv2=(mod+1)/2;
int n,m,L,R,ans;
int ksm(int a,long long b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&L,&R);
	int even=R/2-(L-1)/2,odd=R-L+1-even;
	long long all=1ll*n*m;
	if(all&1){
		printf("%d\n",ksm(R-L+1,all));
		return 0;
	}
	int ans=1ll*(ksm((0ll+even+odd)%mod,all)+ksm((0ll+even-odd+mod)%mod,all))*inv2%mod;
	printf("%d\n",ans);
	return 0;
}