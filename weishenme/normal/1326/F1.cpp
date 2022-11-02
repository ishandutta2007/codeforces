#include<bits/stdc++.h>
using namespace std;
const int N=14;
typedef long long ll;
ll dp[1<<N][1<<6][N],f[1<<N],sum[1<<7];
int n,a[N][N],v[1<<N],rev[1<<N];
char s[N+2][N+2];
ll dfs(int x,int y,int z){
	if (v[x]==1)return 1;
	if (dp[x][y][z]!=-1)return dp[x][y][z];
	dp[x][y][z]=0;
	int t=((1<<(v[x]-2))&y)>0;
	for (int i=0;i<n;i++)
		if (((1<<i)&x)&&i!=z&&a[z][i]==t)dp[x][y][z]+=dfs(x^(1<<z),y^(t<<(v[x]-2)),i);
	return dp[x][y][z];
}
int main(){
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	for (int i=0;i<n;i++)scanf("%s",s[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			a[i][j]=s[i][j]-'0';
	for (int i=0;i<1<<n;i++){
		int j=i;
		while (j){
			v[i]+=j&1;
			j>>=1;
		}
	}
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<(n+1)/2-1;j++)rev[i]+=(i&(1<<j))>>j<<((n+1)/2-2-j);
	for (int i=0;i<1<<n;i++)
		if (v[i]==n/2)for (int j=0;j<n;j++)
			if ((1<<j)&i){
				int t=((1<<n)-1)^i;
				memset(sum,0,sizeof sum);
				for (int k=0;k<n;k++)
					if ((1<<k)&t)for (int z2=0;z2<(1<<((n+1)/2-1));z2++)
						sum[a[j][k]|rev[z2]<<1]+=dfs(t,z2,k);
				for (int z1=0;z1<1<<(n/2-1);z1++)
					for (int z2=0;z2<1<<((n+1)/2);z2++)
						f[z1|(z2<<(n/2-1))]+=dfs(i,z1,j)*sum[z2];
			}
	for (int i=0;i<1<<(n-1);i++)printf("%lld ",f[i]);
}