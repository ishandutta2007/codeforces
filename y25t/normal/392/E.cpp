#include<bits/stdc++.h>
#define N 405

int n,b[N],a[N];

int u[N][N],v[N][N],f[N][N];

int g[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(u,~0x3f,sizeof(u)),memset(v,~0x3f,sizeof(v)),memset(f,~0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		u[i][i]=v[i][i]=0;
		f[i][i]=b[1];
		for(int j=i-1;j;j--)
			f[i][j]=0;
	}
	for(int len=2;len<=n;len++)
		for(int i=1,j=i+len-1;j<=n;i++,j++){
			for(int k=i;k<j;k++){
				if(a[k]+1==a[j])
					u[i][j]=std::max(u[i][j],u[i][k]+f[k+1][j-1]);
				if(a[k]-1==a[j])
					v[i][j]=std::max(v[i][j],v[i][k]+f[k+1][j-1]);
				if(k>i&&a[k]>=a[i]&&a[k]>=a[j]&&2*a[k]-a[i]-a[j]+1<=n)
					f[i][j]=std::max(f[i][j],u[i][k]+v[k][j]+b[2*a[k]-a[i]-a[j]+1]);
				f[i][j]=std::max(f[i][j],f[i][k]+f[k+1][j]);
			}
			if(std::abs(a[j]-a[i])+1<=n)
				f[i][j]=std::max(f[i][j],b[std::abs(a[j]-a[i])+1]+(a[i]<a[j]?u[i][j]:v[i][j]));
		}
	for(int i=1;i<=n;i++){
		g[i]=g[i-1];
		for(int j=0;j<i;j++)
			g[i]=std::max(g[i],g[j]+f[j+1][i]);
	}
	printf("%d\n",g[n]);
}