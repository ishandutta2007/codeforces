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
const int N=5005;
int n;
ll t[N],x[N],f[N];
bool g[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld",&t[i],&x[i]);
	t[n+1]=1ll<<32; x[n+1]=0; ++n;
	For(i,1,n) f[i]=1ll<<50;
	//if ()
	For(i,0,n-1){
		
		if (f[i]<=t[i]){
			f[i+1]=min(f[i+1],max(t[i],f[i]+abs(x[i]-x[i+1])));
			For(j,i+2,n) if (max(t[i],f[i]+abs(x[i]-x[j]))+abs(x[j]-x[i+1])<=t[i+1]) g[i+1][j]=1;
		}
		For(j,i+2,n)
			if (abs(x[i]-x[i+1])<=t[i+1]-t[i])
				g[i+1][j]|=g[i][j];
		if (g[i][i+1]){
			if (i+2<=n) f[i+2]=min(f[i+2],max(t[i+1],t[i]+abs(x[i]-x[i+2])));
			For(j,i+3,n)
				if (max(t[i+1],t[i]+abs(x[i]-x[j]))+abs(x[j]-x[i+2])<=t[i+2])
					g[i+2][j]=1;
		}
	}
	puts(g[n-1][n]||(f[n]<=t[n])?"YES":"NO");
}