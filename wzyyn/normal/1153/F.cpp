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
const int mo=998244353;
const int N=2005;
int n,K,l;
int f[2*N][N];
int g[2*N][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&K,&l);
	f[0][0]=1;
	For(i,1,2*n+1) For(j,1,n){
		f[i][j]=(f[i][j]+f[i-1][j-1])%mo;
		g[i][j]=(g[i][j]+g[i-1][j-1])%mo;
		f[i][j-1]=(f[i][j-1]+1ll*f[i-1][j]*j)%mo;
		g[i][j-1]=(g[i][j-1]+1ll*g[i-1][j]*j)%mo;
		if (j>=K) g[i][j]=(g[i][j]+f[i-1][j])%mo;
	}
	int ans=1ll*l*g[2*n+1][0]%mo;
	//cout<<ans<<' '<<l<<endl; 
	For(i,1,n) ans=2ll*ans*i%mo;
	For(i,1,2*n+1) ans=1ll*ans*power(i,mo-2)%mo;
	printf("%d\n",ans);
}