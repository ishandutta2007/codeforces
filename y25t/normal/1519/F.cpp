#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 10

int n,m,a[N],b[N],c[N][N];

int pw[N];

int f[15625],g[15625];
inline void dfs(int o,int x,int y,int l,int v){
	if(x==m){
		if(!y)
			g[l]=std::min(g[l],v);
		return;
	}
	dfs(o,x+1,y,l,v);
	for(int i=1;i<=y&&i+l/pw[x]%5<=b[x+1];i++)
		dfs(o,x+1,y-i,l+i*pw[x],v+c[o][x+1]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		scanf("%d",&c[i][j]);
	pw[0]=1;
	for(int i=1;i<=m;i++)
		pw[i]=pw[i-1]*5;
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		memset(g,0x3f,sizeof(g));
		for(int l=0;l<pw[m];l++) if(f[l]<inf)
			dfs(i,0,a[i],l,f[l]);
		std::swap(f,g);
	}
	int res=inf;
	for(int i=0;i<pw[m];i++)
		res=std::min(res,f[i]);
	printf("%d\n",res==inf?-1:res);
}