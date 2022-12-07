#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=5005;
const int mo=998244353;
int h,w,n,ans,S1,S2;
int f[N][N],g[N][N];
int fac[N],inv[N];
int visx[N],visy[N];
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[x-y]%mo;
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,2,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d%d",&h,&w,&n);
	For(i,1,2*n){
		int x,y;
		scanf("%d%d",&x,&y);
		visx[x]=visy[y]=1;
	}
	visx[0]=visy[0]=1;
	f[0][0]=g[0][0]=1;
	For(i,1,h){
		For(j,0,i/2) f[i][j]=f[i-1][j];
		if (visx[i]||visx[i-1]) continue;
		For(j,1,i/2) f[i][j]=(f[i][j]+f[i-2][j-1])%mo;
	}
	For(i,1,w){
		For(j,0,i/2) g[i][j]=g[i-1][j];
		if (visy[i]||visy[i-1]) continue;
		For(j,1,i/2) g[i][j]=(g[i][j]+g[i-2][j-1])%mo;
	}
	For(i,1,h) S1+=!visx[i];
	For(i,1,w) S2+=!visy[i];
	For(i,0,S1/2) For(j,0,S2/2)
		ans=(ans+1ll*f[h][i]*g[w][j]%mo*C(S1-2*i,j)%mo*C(S2-2*j,i))%mo;
	printf("%d\n",ans);
}