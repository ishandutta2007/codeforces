#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxk=11;
int n,m,k;
int f[maxn][maxn][maxk],a[maxn][maxn],b[maxn][maxn];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				printf("-1%c",j==m? '\n':' ');
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	k>>=1;
	for(int t=1;t<=k;t++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				f[i][j][t]=1e9;
				if(i>1)
					f[i][j][t]=min(f[i][j][t],f[i-1][j][t-1]+b[i-1][j]);
				if(i<n)
					f[i][j][t]=min(f[i][j][t],f[i+1][j][t-1]+b[i][j]);
				if(j>1)
					f[i][j][t]=min(f[i][j][t],f[i][j-1][t-1]+a[i][j-1]);
				if(j<m)
					f[i][j][t]=min(f[i][j][t],f[i][j+1][t-1]+a[i][j]);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%c",f[i][j][k]*2,j==m? '\n':' ');
	return 0;
}