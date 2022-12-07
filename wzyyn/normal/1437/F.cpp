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
const int mo=998244353;
int n,a[N],su[N],pr[N];
int f[N][N],g[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,0,n){
		int p1=0,p2=i+1;
		for (;a[p1+1]*2<=a[i];++p1);
		for (;p2<=n&&a[i]*2>a[p2];++p2);
		pr[i]=p1; su[i]=p2;
		//cout<<pr[i]<<' '<<su[i]<<endl;
	}
	For(i,1,n) f[i][1]=1;
	For(i,1,n) For(j,1,i){
		g[i][j]=(g[i][j]+g[i-1][j])%mo; 
		f[i][j]=(f[i][j]+g[i][j]+1ll*f[i][j-1]*(pr[i]+1-(j-1)))%mo;
		//cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		g[su[i]][j+1]=(g[su[i]][j+1]+f[i][j])%mo;
	}
	cout<<f[n][n]<<endl;
}