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
const int N=405;
int n,m,a[N][N];
int f[N][N],ans;
short g[N][N*N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n){
		Rep(j,m,1) For(k,j,m){
			f[j][k]=max(f[j][k],max(f[j+1][k],f[j][k-1]));
			f[j][k]=max(f[j][k],(int)max(g[j][a[i][k]],g[k][a[i][j]]));
			if (j!=k&&a[i][j]==a[i][k]) f[j][k]=i;
			ans=max(ans,(k-j+1)*(i-f[j][k]));
			//cout<<i<<' '<<j<<' '<<k<<' '<<f[j][k]<<endl;
		}
		For(j,1,m) g[j][a[i][j]]=i;
	}
	printf("%d\n",ans);
}