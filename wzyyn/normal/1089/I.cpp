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
const int N=505;
int f[N],g[N],fac[N],n,mo;
int F[N],G[N][N];
void init(){
	n=400; //mo=998244353;
	g[1]=F[0]=F[1]=1; f[1]=0; fac[0]=1;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mo;
	G[0][0]=G[1][1]=1;
	For(i,2,n){
		For(j,1,i-1) F[i]=(F[i]+1ll*F[j]*(fac[i-j]+mo-f[i-j]))%mo;
		f[i]=F[i]; F[i]=fac[i];
		For(j,0,i-1) For(k,0,j)	G[i][k+1]=(G[i][k+1]+1ll*G[j][k]*fac[i-j])%mo;
		g[i]=(fac[i]+mo-2ll*f[i]%mo)%mo;
		For(j,2,i-1) g[i]=(g[i]+mo-1ll*g[j]*G[i][j]%mo)%mo;
	}
}
int main(){
	int T;
	scanf("%d%d",&T,&mo);
	init();
	while (T--){
		int x;
		scanf("%d",&x);
		printf("%d\n",x==2?2:g[x]);
	}
}