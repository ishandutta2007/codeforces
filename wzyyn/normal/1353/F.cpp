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
const int N=105;
int n,m;
ll a[N][N];
ll f[N][N];
void solve(){
	ll ans=1ll<<60;
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%lld",&a[i][j]);
	For(i,1,n) For(j,1,m) a[i][j]-=i+j;
	For(i,1,n) For(j,1,m){
		For(x,1,n) For(y,1,m){
			f[x][y]=1ll<<60;
			if (a[x][y]<a[i][j]) continue;
			if (x==1&&y==1) f[x][y]=0;
			if (x!=1) f[x][y]=min(f[x][y],f[x-1][y]);
			if (y!=1) f[x][y]=min(f[x][y],f[x][y-1]);
			f[x][y]+=a[x][y]-a[i][j];
		}
		ans=min(ans,f[n][m]);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}