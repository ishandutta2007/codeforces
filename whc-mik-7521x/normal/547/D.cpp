#include<bits/stdc++.h>
using namespace std;
struct edge{
	int nex,to;
}ed[10000005];
int h[200005],cnt;
int n,col[200005],xm[200005],ym[200005];
void add(int x,int y){
	cnt++;
	ed[cnt].to=y;
	ed[cnt].nex=h[x];
	h[x]=cnt;
}
void dfs(int x,int co){
	col[x]=co;
	for(int i=h[x];i;i=ed[i].nex){
		int v=ed[i].to;
		if(!col[v])dfs(v,3-co);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(xm[x])add(i,xm[x]),add(xm[x],i),xm[x]=0;
		else xm[x]=i;
		if(ym[y])add(i,ym[y]),add(ym[y],i),ym[y]=0;
		else ym[y]=i;
	}
	for(int i=1;i<=n;i++){
		if(!col[i])col[i]=1,dfs(i,1);
	}
	for(int i=1;i<=n;i++){
		printf("%c","\nrb"[col[i]]);
	}
	return 0;
}