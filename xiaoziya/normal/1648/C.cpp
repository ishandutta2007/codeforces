#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=200005,mod=998244353;
int n,m,ans,all,cur;
int a[maxn],b[maxn],fac[maxn],nfac[maxn],inv[maxn],cnt[maxn],bcnt[maxn],t[maxn];
void update(int x,int v){
	for(int i=x;i<=200000;i+=lowbit(i))
		t[i]+=v;
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=t[i];
	return res;
}
int main(){
	fac[0]=fac[1]=nfac[0]=nfac[1]=inv[1]=1;
	for(int i=2;i<maxn;i++)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod,nfac[i]=1ll*nfac[i-1]*inv[i]%mod;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	all=1;
	for(int i=1;i<=200000;i++){
		all=1ll*all*nfac[cnt[i]]%mod;
		update(i,cnt[i]);
	}
	for(int i=1;i<=n+1&&i<=m;i++){//lcp
		if(i==n+1){
			ans=(ans+1)%mod;
			continue;
		}
		int tot=query(b[i]-1);
		ans=(ans+1ll*fac[n-i]*all%mod*tot)%mod;
//		printf("i=%d val=%d\n",i,1ll*fac[n-i]*all%mod*tot);
		all=1ll*all*fac[cnt[b[i]]-bcnt[b[i]]]%mod,bcnt[b[i]]++,all=1ll*all*nfac[cnt[b[i]]-bcnt[b[i]]]%mod;
		update(b[i],-1);
		if(bcnt[b[i]]>cnt[b[i]])
			break;
	}
	printf("%d\n",ans);
	return 0;
}