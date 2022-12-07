#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=(1<<17)+5;
int inv[N*2],fac[N*2];
int n,K,mod,cnt[N];
int f[18][N],g[18][N];
ull h[18][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mod)
		if (y&1) s=1ll*s*x%mod;
	return s;
}
void init(){
	inv[0]=inv[1]=fac[0]=1;
	For(i,2,2*N-1) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	For(i,1,2*N-1) inv[i]=1ll*inv[i-1]*inv[i]%mod;
	For(i,1,2*N-1) fac[i]=1ll*fac[i-1]*i%mod;
	For(i,0,N-1) cnt[i]=cnt[i/2]+(i&1);
}
void DFT(int *a,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++)
				a[i+j+d]=(a[i+j+d]+a[i+j])%mod;
} 
void IDFT(int *a,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++)
				a[i+j+d]=(a[i+j+d]+mod-a[i+j])%mod;
} 
int main(){
	scanf("%d%d%d",&n,&K,&mod);
	int ans=power(K,n);
	if (n&1){
		printf("%d\n",ans);
		exit(0);
	}
	init();
	For(i,0,n/2) f[cnt[i]][i]=inv[i*2];
	int lim=cnt[n/2];
	For(i,0,lim) DFT(f[i],1<<17);
	For(i,0,lim) For(j,0,(1<<17)-1) g[i][j]=f[i][j];
	For(i,2,K){
		memset(h,0,sizeof(h));
		For(j,0,lim) For(k,0,lim-j) For(l,0,(1<<17)-1) h[j+k][l]+=1ll*g[j][l]*f[k][l];
		For(j,0,lim) For(l,0,(1<<17)+1) g[j][l]=h[j][l]%mod;
	}
	//250000 26 419059819
	//cout<<g[cnt[n/2]][0]<<' '<<g[cnt[n/2]][2]<<endl;
	IDFT(g[cnt[n/2]],1<<17);
	//cout<<g[1][2]<<' '<<fac[n]<<endl;
	ans=(ans+mod-1ll*fac[n]*g[cnt[n/2]][n/2]%mod)%mod;
	printf("%d\n",ans);
}