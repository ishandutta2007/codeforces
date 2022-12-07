#include<bits/stdc++.h>

using namespace std;

const int N=500005;
const int mo=998244353;
int n,ans;
int f[N][2];
int g[3][2];
void solve(){
	ans=0;
	scanf("%d",&n);
	for (int i=0;i<=n+2;i++)
		f[i][0]=f[i][1]=0;
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for (int j=-1;j<=1;j++)
			for (int k=0;k<=1;k++)
				if (j+x>=0) g[j+1][k]=f[j+x][k];
				else g[j+1][k]=0;
		for (int j=-1;j<=1;j++)
			for (int k=0;k<=1;k++){
				int nj,nk;
				if (j==1) nj=j,nk=k;
				else if (j==0) nj=j+1+k,nk=0;
				else nj=j,nk=1;
				if (nj!=2&&x+nj>=0){
					ans=(ans+g[j+1][k])%mo;
					f[x+nj][nk]=(f[x+nj][nk]+g[j+1][k])%mo;
				}
			}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}