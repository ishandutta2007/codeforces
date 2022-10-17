#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=505,inf=1e9;
int n,a[N],f[2][N][N],g[N][N];
inline void Max(int &a,int b){if(a<b)a=b;}
int main(){
	n=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[0][i][j]=f[1][i][j]=-inf;
	int c=0;
	f[0][0][0]=0;
	g[0][0]=0;
	for(int i=1;i<=n;i++,c^=1){
		for(int j=0;j<i;j++){
			for(int k=0;k<=n;k++){
				Max(f[c^1][j+1][k],f[c][j][k]+a[k]);
			}
		}
		for(int j=0;j<i;j++){
			for(int k=i;k<=n;k++){
				if(j+k-i>i)break;
				Max(f[c^1][j+k-i][k],g[j][k-1]+a[k]);
			}
		}
		for(int j=0;j<=n;j++){
			g[j][0]=-inf;
			for(int k=0;k<=n;k++){
				if(j<=i){
					if(k>0)g[j][k]=g[j][k-1];
					Max(g[j][k],f[c^1][j][k]);
				}else f[c^1][j][k]=-inf;
				f[c][j][k]=-inf;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)Max(ans,g[i][n]);
	cout<<ans<<endl;
	return 0;
}