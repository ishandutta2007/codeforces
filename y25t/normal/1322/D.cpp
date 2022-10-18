#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 2005

int n,m;

int l[N],s[N],c[N<<1];

int f[N<<1][N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=n;i;i--)
		scanf("%d",&l[i]);
	for(int i=n;i;i--)
		scanf("%d",&s[i]);
	for(int i=1;i<=n+m;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n+m;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=-inf;
	for(int i=1;i<=n;i++){
		for(int j=n;j;j--)
			f[l[i]][j]=std::max(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
		for(int j=l[i];j<=n+m;j++)
			for(int k=0;k<=(n>>(j-l[i]));k++)
				f[j+1][k/2]=std::max(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	printf("%d\n",f[n+m][0]);
}