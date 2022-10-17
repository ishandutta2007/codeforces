#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=200005,mod=998244353;
int T,n,la,ra,lb,rb,ans,oka,okb,flg,tot,fucka,fuckb,fuckc,fuckd;
int fac[maxn],nfac[maxn],inv[maxn];
string s;
inline int C(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[b]%mod*nfac[a-b]%mod;
}
int main(){
	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;
	for(int i=2;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod,nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>s,la+=s[0]=='W',lb+=s[0]=='B',ra+=s[1]=='W',rb+=s[1]=='B',flg|=s=="BB",flg|=s=="WW",oka+=s=="WB",okb+=s=="BW",tot+=s=="??",fucka|=s=="W?",fuckb|=s=="?B",fuckc|=s=="B?",fuckd|=s=="?W";
	if(la+ra>n||lb+rb>n){
		puts("0");
		return 0;
	}
	ans=C(n+n-la-lb-ra-rb,n-la-ra);
	if(flg==0){
		int res=1;
		for(int i=1;i<=tot;i++)
			res=(res+res)%mod;
		ans=(ans-res+mod)%mod;
		ans=(ans+(oka==0&&fucka==0&&fuckb==0)+(okb==0&&fuckc==0&&fuckd==0))%mod;
	}
	printf("%d\n",ans);
	return 0;
}