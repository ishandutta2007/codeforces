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
const int mo=1000000007;
const int N=200005,M=2005;
int n,m,K,ans,v[25];
int f[25][M],tr[M][M];
int fac[N],inv[N];
pii a[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo; 
}
int PTH(int x,int y,int X,int Y){
	if (x>X||y>Y) return 0;
	return 1ll*fac[X-x+Y-y]*inv[X-x]%mo*inv[Y-y]%mo;
}
int main(){
	init();
	scanf("%d%d%d%d",&n,&m,&K,&v[1]);
	For(i,2,22) v[i]=(v[i-1]+1)/2;
	For(i,1,K) scanf("%d%d",&a[i].fi,&a[i].se);
	a[++K]=pii(1,1); a[++K]=pii(n,m);
	sort(a+1,a+K+1); f[0][1]=1;
	For(i,1,K) For(j,i+1,K) tr[i][j]=PTH(a[i].fi,a[i].se,a[j].fi,a[j].se); 
	For(i,1,22) if (v[i]!=1){
		For(j,1,K) For(k,j+1,K) f[i][k]=(f[i][k]+1ll*tr[j][k]*f[i-1][j])%mo;
		For(j,1,K) For(k,j+1,K) f[i][k]=(f[i][k]+mo-1ll*tr[j][k]*f[i][j]%mo)%mo;
		ans=(ans+1ll*(v[i]-1)*f[i][K])%mo;
	}
	ans=1ll*ans*power(PTH(1,1,n,m),mo-2)%mo;
	printf("%d\n",(ans+1)%mo);
}