#include<bits/stdc++.h>

using namespace std;

const int N=205;
int n,P,ans;
int inv[N],fac[N];
int f[N][N],g[N][N];
void init(){
	inv[0]=inv[1]=fac[0]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[P%i]*(P-P/i)%P;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%P;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%P;
}
int main(){
	scanf("%d%d",&n,&P);
	init();
	f[0][0]=1;
	for (int i=1;i<=n+1&&i*(i-1)/2<=n+1;i++){
		memset(g,0,sizeof(g));
		if (i!=1){
			for (int s=0;s<=n+1;s++) if (s+(i-2)<=n+2-i)
				ans=(ans+1ll*f[i-2][s]*inv[n-(i-2)]%P*fac[n])%P;
		}
		for (int j=i-1;j<=n;j++)
			for (int k=1;k<=n-j;k++)
				for (int s=0;s<=n+1-j;s++)
					g[j+k][s+j]=(g[j+k][s+j]+1ll*f[j][s]*inv[k])%P;
		for (int s=0;s<=n+1;s++) if (s<=n+2-i)
			ans=(ans+1ll*fac[n]*g[n][s])%P;
		for (int j=i-1;j<=n;j++)
			for (int s=0;s<=n+1-j;s++)
				g[j][s+j]=(g[j][s+j]+f[j][s])%P;
		memcpy(f,g,sizeof(f));
	}
	cout<<ans%P<<endl;
}
/*
f[i][j][k]:  n+2-i  j ,  - (n+2-i)  k 
 i
*/