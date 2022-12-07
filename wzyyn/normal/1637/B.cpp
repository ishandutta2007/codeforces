#include<bits/stdc++.h>

using namespace std;

const int N=105;
int n,a[N],tg[N];
int co[N][N],f[N][N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int p=0;
		memset(tg,0,sizeof(tg));
		for (int j=i;j<=n;j++){
			tg[min(a[i],101)]=1;
			for (;tg[p];++p);
			co[i][j]=p+1;
		}
	}
	memcpy(f,co,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			for (int k=j+1;k<=n;k++)
				f[i][k]=max(f[i][k],f[i][j]+co[j+1][k]);
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			ans+=f[i][j];
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}