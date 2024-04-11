#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=250005,M=1<<17,D=18;

int P;
int power(int a,int t){
	int r=1;
	while(t){
		if(t&1)r=(ll)r*a%P;
		a=(ll)a*a%P;t>>=1;
	}
	return r;
}

int L,K,fac[N],n,m,bit[20],ifac[N],bitcnt[N];
ll suma[D][M],sumc[D][M];
ull dp[D][M],tmp[D][M];

int main(){
	scanf("%d%d%d",&L,&K,&P);
	fac[0]=1;
	for(int i=1;i<=L;i++){
		fac[i]=(ll)fac[i-1]*i%P;
		bitcnt[i]=bitcnt[i>>1]+(i&1);
	}
	ll all=power(K,L);
	if(L&1)printf("%lld\n",all),exit(0);
	ifac[L]=power(fac[L],P-2);
	for(int i=L;i>=1;i--)ifac[i-1]=(ll)ifac[i]*i%P;
	for(int i=1;(1<<i)<=L;i++)if(L>>i&1)bit[n++]=1<<i;
	m=1<<n;
	for(int i=0;i<m;i++){
		int s=0;
		for(int j=0;j<n;j++)if(i>>j&1)s+=bit[j];
		suma[bitcnt[i]][i]=ifac[s];
	}
	for(int t=0;t<=n;t++){
		int i,j,k,l;
		ll*a=suma[t];
		for(l=m;l>=2;l>>=1)for(j=0,i=l>>1;j<m;j+=l)for(k=0;k<i;k++)a[j+k+i]+=a[j+k];
		for(j=0;j<m;j++)a[j]=a[j]%P;
	}
	for(int t=0;t<=n;t++)memcpy(dp[t],suma[t],m<<3);
	int cc=0,revK=0;
	while(K)(revK<<=1)|=K&1,cc++,K>>=1;
	for(cc--,revK>>=1;cc;cc--,revK>>=1){
		for(int t=0;t<=n;t++)memset(tmp[t],0,m<<3);
		for(int a=0;a<=n;a++)for(int j=0;j<m;j++)
			if(dp[a][j])for(int l=a;l<=n;l++)tmp[l][j]+=dp[a][j]*dp[l-a][j];
		for(int t=0;t<=n;t++)for(int j=0;j<m;j++)dp[t][j]=tmp[t][j]%P;
		if(revK&1){
			for(int t=0;t<=n;t++)memset(tmp[t],0,m<<3);
			for(int a=0;a<=n;a++)for(int j=0;j<m;j++)
				if(dp[a][j])for(int l=a;l<=n;l++)tmp[l][j]+=dp[a][j]*suma[l-a][j];
			for(int t=0;t<=n;t++)for(int j=0;j<m;j++)dp[t][j]=tmp[t][j]%P;
		}
	}
	for(int t=0;t<=n;t++)memcpy(sumc[t],dp[t],m<<3);
	for(int t=0;t<=n;t++){
		int i,j,k,l;
		ll*a=sumc[t];
		for(l=2;l<=m;l<<=1)for(j=0,i=l>>1;j<m;j+=l)for(k=0;k<i;k++)a[j+k+i]-=a[j+k];
		for(j=0;j<m;j++)a[j]=(a[j]%P+P)%P;
	}
	ll ans=(all-sumc[n][(1<<n)-1]*fac[L]%P+P)%P;
	printf("%lld\n",ans);
	return 0;
}