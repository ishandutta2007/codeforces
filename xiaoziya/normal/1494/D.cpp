#include<bits/stdc++.h>
using namespace std;
const int maxn=500*500+5;
int n,m,T,N;
int g[maxn],val[maxn],fa[maxn],id[maxn],dsu[maxn],x[maxn],y[maxn],nv[maxn];
vector<int>v[maxn];
inline int getpos(int x,int y){
	return (x-1)*m+y;
}
inline int cmp(int a,int b){
	return g[a]<g[b];
}
int find(int x){
	return dsu[x]==x? x:dsu[x]=find(dsu[x]);
}
void dfs(int x,int lst,int f){
	int now=f;
	if(val[x]!=lst){
		if(x<=m)
			fa[x]=f,nv[x]=val[x];
		else now=++N,fa[now]=f,nv[now]=val[x];
	}
	for(int i=0;i<v[x].size();i++)
		dfs(v[x][i],val[x],now);
}
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&g[getpos(i,j)]),x[getpos(i,j)]=i,y[getpos(i,j)]=j,id[getpos(i,j)]=getpos(i,j);
	sort(id+1,id+1+m*m,cmp);
	n=m;
	for(int i=1;i<=m;i++)
		dsu[i]=i,val[i]=g[getpos(i,i)];
	for(int i=1;i<=m*m;i++){
		int k=id[i],a=find(x[k]),b=find(y[k]);
		if(a==b)
			continue;
		n++,val[n]=g[k],dsu[n]=dsu[a]=dsu[b]=n,v[n].push_back(a),v[n].push_back(b);
	}
	N=m,dfs(n,-1,0);
	printf("%d\n",N);
	for(int i=1;i<=N;i++)
		printf("%d%c",nv[i],i==N? '\n':' ');
	printf("%d\n",m+1);
	for(int i=1;i<=N;i++)
		if(i!=m+1)
			printf("%d %d\n",i,fa[i]);
	return 0;
}