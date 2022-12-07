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
int n,k,a[N],b[N];
int f[N][N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&a[i],&b[i]);
	f[0][0]=1;
	For(i,1,n) For(v1,0,k-1) if (f[i-1][v1])
		For(v2,0,k-1) if (v2<=a[i]&&(k-v2)%k<=b[i])
			f[i][(v1+a[i]-v2)%k]=1;
	ll sum=0,ans=0;
	For(i,1,n) sum+=a[i]+b[i];
	For(v,0,k-1) if (f[n][v])
		ans=max(ans,(sum-v)/k);
	printf("%lld\n",ans);
}