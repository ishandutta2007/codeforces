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
const int mo=1000000007;
int n,a[N],f[N][N],g[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) g[i][i]=f[i][i]=1;
	For(l,2,n) For(i,1,n-l+1){
		int j=i+l-1; f[i][j]=g[i][j]=f[i+1][j];
		For(k,i+1,j) if (a[i]<a[k])
			f[i][j]=(f[i][j]+1ll*g[i][k-1]*f[k][j])%mo;
		//cout<<i<<' '<<j<<' '<<g[i][j]<<' '<<f[i][j]<<endl;
	}
	printf("%d\n",g[1][n]);
}