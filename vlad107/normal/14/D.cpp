#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define MAXN 222

std::vector<int>g[MAXN];
int n,r1,r2,ff,O=0,f[MAXN],res=0;
bool was[MAXN];

void dfs(int x,int px,int dl){
	was[x]=true;
	if (x==ff){
		r1=dl;
		return;	
	}
	if (r1>=0)return;
	for (int i=0;i<g[x].size();i++)
		if (px!=g[x][i]){
			dfs(g[x][i],x,1+dl);
			if (r1>=0)return;
		}
	was[x]=false;
}
void dfs2(int x,int px){
	int max1=0,max2=0;
	for (int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if (y==px)continue;
		if (was[y])continue;
		dfs2(y,x);
		if (f[y]>=max1){
			max2=max1;
			max1=f[y];
		}else
		if (f[y]>max2)
			max2=f[y];
	}
	f[x]=max1+1;
	if (max1+max2>r2)r2=max1+max2;
}

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int x=0;x<n-1;x++)
		for (int y=x+1;y<n;y++){
			ff=y;
			r1=-1;
			memset(was,false,sizeof(was));
			dfs(x,-1,0);
			r2=0;
			memset(f,0,sizeof(f));
			for (int i=0;i<n;i++)
				if (!was[i]&&!f[i])dfs2(i,-1);
			if (r1*r2>res)res=r1*r2;
		}
	printf("%d\n",res);
}