#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 998244353;
const int N = 1e5+9;
int F[N],pri[N],tot;
ll mu[N];
void init(){
	F[1]=1,tot=0,mu[1]=1;
	for(int i=2;i<=N-9;i++){
		if(!F[i]) pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&pri[j]*i<=N-9;j++){
			F[pri[j]*i]=1,mu[pri[j]*i]=-mu[i];
			if(i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			}
		}
	}
	return ;
}

int n,m;
ll a[N],b[N],f[59][N],sum[59][N];

int main(){
	init();	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll t=mu[i];t=(t+mod)%mod;
		if(!mu[i]) continue;
		int up=m/i;
		for(int x=0;x<=n;x++)
			for(int y=0;y<=up;y++) f[x][y]=0,sum[x][y]=0;
		f[0][0]=1;
		for(int j=0;j<=up;j++) sum[0][j]=1;
		for(int j=1;j<=n;j++){
			ll l=(a[j]-1)/i,r=b[j]/i;
			for(int k=0;k<=up;k++){
				ll x=l+1,y=min((int)r,up)+1;
				if(k-x>=0) (f[j][k]+=sum[j-1][k-x])%mod;
				if(k-y>=0) (f[j][k]+=(mod-sum[j-1][k-y]))%mod;
//				for(ll p=x;p<=y;p++){
//					if(k-p>=0) (f[j][k]+=f[j-1][k-p])%=mod;
//				}
			}
			sum[j][0]=f[j][0];
			for(int k=1;k<=up;k++)
				sum[j][k]=(sum[j][k-1]+f[j][k])%mod;
		}
		ll p=0;
		for(int k=0;k<=up;k++) (p+=f[n][k])%=mod;
		t=t*p%mod;
		(ans+=t)%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}