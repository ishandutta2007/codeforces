#include<bits/stdc++.h>
#define N 205

int P;
inline void fmo(int &x){
	x+=(x>>31)&P;
}

int fac[N],inv[N],ifac[N];
inline void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=x;i++)
		fmo(inv[i]=-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=x;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}

int n;

int f[N][N][N];
inline int sol(int mn){
	memset(f,0,sizeof(f));
	f[mn-1][0][0]=1;
	for(int x=mn-1;x<=n;x++)
		for(int i=0;i<=n;i++)
			for(int s=0;s<=mn;s++) if(f[x][i][s])
				for(int k=x==mn-1?1:0;i+k<=n&&s+(x+1-mn)*k<=mn&&mn*(x+1)>=s+i*mn+k*(x+1);k++)
					fmo(f[x+1][i+k][s+(x+1-mn)*k]+=1ll*f[x][i][s]*ifac[k]%P-P);
	int res=0;
	for(int s=0;s<=mn;s++)
		fmo(res+=f[n+1][n][s]-P);
	return res;
}

int ans;

int main(){
	scanf("%d%d",&n,&P);
	init(n);
	for(int i=std::max(n-18,1);i<=n+1;i++)
		fmo(ans+=sol(i)-P);
	ans=1ll*ans*fac[n]%P;
	printf("%d\n",ans);
}