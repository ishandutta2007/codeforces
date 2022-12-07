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
const int N=2005;
int n,a[N][N],vis[N];
ll d[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,i+1,n)
		scanf("%d",&a[i][j]);
	int mn=2e9;
	For(i,1,n) For(j,i+1,n)
		mn=min(mn,a[i][j]);
	For(i,1,n) For(j,i+1,n)
		a[j][i]=a[i][j]=a[i][j]-mn;
	For(i,1,n){
		d[i]=1ll<<50;
		For(j,1,n) if (j!=i)
			d[i]=min(d[i],2ll*a[i][j]);
	}
	For(i,1,n){
		int v=-1;
		For(j,1,n)
			if (!vis[j]&&(v==-1||d[j]<d[v]))
				v=j;
		vis[v]=1;
		For(j,1,n)
			d[j]=min(d[j],d[v]+a[v][j]);
	}
	For(i,1,n)
		printf("%lld\n",d[i]+1ll*mn*(n-1));
}