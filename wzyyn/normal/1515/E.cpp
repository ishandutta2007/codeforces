#include<bits/stdc++.h>
using namespace std;

const int N=405;
int n,mo;
int C[N][N];
int f[N][N];
int W[N];
int main(){
	scanf("%d%d",&n,&mo);
	for (int i=0;i<=n;i++)
		C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			W[i]=(W[i]+C[i-1][j-1])%mo;
	f[0][0]=1;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++){
			//cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
			for (int k=1;i+k+1<=n+1;k++)
				f[i+k+1][j+k]=(f[i+k+1][j+k]+1ll*f[i][j]*W[k]%mo*C[j+k][k])%mo;
		}
	int ans=0;
	for (int i=0;i<=n;i++)
		ans=(ans+f[n+1][i])%mo;
	cout<<ans<<endl;
}