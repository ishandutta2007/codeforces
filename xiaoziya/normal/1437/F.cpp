#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=5005,mod=998244353;
int n;
int a[maxn],f[maxn],rec[maxn],fac[maxn],nfac[maxn];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
inline int A(int a,int b){
	return a<b? 0:1ll*fac[a]*nfac[a-b]%mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	fac[0]=nfac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod,nfac[i]=ksm(fac[i],mod-2);
	sort(a+1,a+1+n);
	if(a[n-1]*2>a[n]){
		puts("0");
		return 0;
	}
	f[0]=1,rec[0]=-1;
	int sum=fac[n-1];
	for(int i=1,l=0;i<=n;i++){
		int j=i;
		while(j+1<=n&&a[j+1]==a[i])
			j++;
		while(l+1<=n&&2*a[l+1]<=a[i])
			l++,sum=(sum+1ll*f[l]*fac[n-rec[l]-2])%mod;
		int nowf=1ll*sum*nfac[n-l-1]%mod;
		for(int k=i;k<=j;k++)
			f[k]=nowf,rec[k]=l;
		i=j;
	}
	printf("%d\n",f[n]);
	return 0;
}