#include<bits/stdc++.h>
using namespace std;
int n,m,a[109];
int g[109][109];

int main(){
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)	
			for(int k=1;k<=n;k++)
				if(g[i][j]==1&&g[j][k]==1&&g[k][i]==1){
					if(ans==-1||ans>a[i]+a[j]+a[k]) ans=a[i]+a[j]+a[k];
				}
	printf("%d\n",ans);			
	return 0;
}