#include<bits/stdc++.h>
using namespace std;

const int N=205;
const int mo=1000000007;
int n,ans;
int e[N][N];
int f[N][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	memset(e,30,sizeof(e));
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	for (int i=1;i<=n;i++) f[0][i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=(f[i-1][j]+f[i][j-1])*1ll*(mo+1)/2%mo;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	for (int x=1;x<=n;x++)
		for (int y=1;y<=n;y++)
			for (int z=1;z<y;z++){
				int d=(e[x][y]+e[x][z]-e[y][z])/2;
				ans=(ans+f[e[x][y]-d][e[x][z]-d])%mo;
			}
	ans=1ll*ans*power(n,mo-2)%mo;
	cout<<ans<<endl;
}