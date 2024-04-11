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
const int N=555;
ll a[N][N],b[N][N];
int n,k,m,x[N],y[N];
int main(){
	scanf("%d",&k); n=(1<<k);
	For(i,0,n-1) For(j,0,n-1)
		scanf("%lld",&a[i][j]);
	scanf("%d",&m);
	For(i,1,m)
		scanf("%d%d",&x[i],&y[i]);
	Rep(i,m,1){
		x[i]=(x[i]+n-x[1])%n;
		y[i]=(y[i]+n-y[1])%n;
	}
	For(i,1,k){
		For(j,0,n-1) For(k,0,n-1) For(l,1,m)
			b[j][k]^=a[(j+n-x[l])%n][(k+n-y[l])%n];
		memcpy(a,b,sizeof(b));
		memset(b,0,sizeof(b));
		For(j,1,m){
			x[j]=x[j]*2%n;
			y[j]=y[j]*2%n;
		}
	}
	int ans=0;
	For(i,0,n-1) For(j,0,n-1)
		if (a[i][j]) ++ans;
	printf("%d\n",ans);
}