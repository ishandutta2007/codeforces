#include<bits/stdc++.h>
#define N 105

int P;
inline int fmo(int x){
	return x+((x>>31)&P);
}

int fac[N],C[N][N];

int f[N][N][N];
inline int dfs(int n,int m,int k){
	if(k>(n+1)/2)
		return 0;
	if(m>n)
		return (!k)*fac[n];
	if(!n)
		return !k;
	if(m==1)
		return (k==1)*fac[n];
	if(~f[n][m][k])
		return f[n][m][k];
	int res=0;
	for(int i=0;i<=n-1;i++)
		for(int j=0;j<=k;j++)
			res=fmo(res+1ll*dfs(i,m-1,j)*dfs(n-1-i,m-1,k-j)%P*C[n-1][i]%P-P);
	return f[n][m][k]=res;
}

int n,m,k;

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&P);
	memset(f,-1,sizeof(f));
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	for(int i=0;i<=n;i++)
		C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=fmo(C[i-1][j]+C[i-1][j-1]-P);
	printf("%d\n",dfs(n,m,k));
}