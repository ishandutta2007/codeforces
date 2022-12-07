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
int n,d,mod,ans,tr[15];
int f[1005],inv[15];
int g[15][1005];
int main(){
	scanf("%d%d%d",&n,&d,&mod);
	if (n==1) return puts("1"),0;
	For(i,0,d) g[i][i]=1;
	f[1]=inv[0]=inv[1]=1;
	For(i,2,d) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	For(i,2,n/2){
		f[i]=g[d-1][i-1]; tr[0]=1;
		//cout<<i<<' '<<f[i]<<endl;
		For(j,1,d) tr[j]=1ll*tr[j-1]*inv[j]%mod*(f[i]+j-1)%mod;
		Rep(j,d,0) For(k,1,d-j) For(l,0,n-k*i)
			g[j+k][l+k*i]=(g[j+k][l+k*i]+1ll*g[j][l]*tr[k])%mod;
		if (i==(n-1)/2) ans=g[d][n-1];
	}
	//int ans=g[d][n-1];
	if (n%2==0) ans=(ans+1ll*f[n/2]*(f[n/2]+1)/2)%mod;
	printf("%d\n",ans);
}