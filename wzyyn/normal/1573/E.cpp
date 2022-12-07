#include<bits/stdc++.h>

using namespace std;

const int N=3005;
int n,a[N],f[N],nx[N],g[N][N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),f[i]=n+2;
	for (int i=n;i>=1;i--)
		nx[i]=f[a[i]],f[a[i]]=i;
	for (int i=0;i<=n;i++)
		for (int j=i;j<=n;j++)
			g[i][j]=0;
	for (int i=n;i>=1;i--)
		for (int j=i+1;j<=n;j++){
			g[i][j]=g[i+1][j];
			for (int k=nx[i];k<=j;k=nx[k])
				g[i][j]=max(g[i][j],g[i+1][k-1]+g[k][j]+1);
		}
	cout<<n-1-g[1][n]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}