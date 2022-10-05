#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int from,to;
	long long cost;
} e[200005];
long long dist[810][810];
int tot=0,c[200005];
bool on[810][810];
vector<int> g[810];
bool cmp(edge e,edge b){
	return e.cost<b.cost;
}
int fa[810];
void init(){
	for(int i=1;i<=800;i++)	fa[i]=i;
}
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
void link(int x,int y){
	fa[find(x)]=find(y);
}
void kruskal(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=min(k,m);i++){
		if(!c[e[i].from])	c[e[i].from]=++tot;
		if(!c[e[i].to])		c[e[i].to]=++tot;
		link(c[e[i].from],c[e[i].to]);
		dist[c[e[i].from]][c[e[i].to]]=dist[c[e[i].to]][c[e[i].from]]=e[i].cost;
	}
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=tot;j++)
			if(find(i)==find(j)){
				on[i][j]=1;
				g[i].push_back(j);
			}
}
void floyd(){
	for(int l=1;l<=tot;l++)
		for(int i=1;i<=tot;i++)
			if(on[l][i])
				for(int j=0;j<g[i].size();j++)
					dist[i][g[i][j]]=min(dist[i][g[i][j]],dist[i][l]+dist[l][g[i][j]]);
}
int main(){
	cin>>n>>m>>k;
	init();
	memset(dist,0x3f3f3f3f,sizeof(dist));
	for(int i=1;i<=800;i++)	dist[i][i]=0;
	for(int i=1;i<=m;i++)	cin>>e[i].from>>e[i].to>>e[i].cost;
	kruskal();floyd();
	priority_queue<long long,vector<long long>,greater<long long> > q;
	for(int i=1;i<=tot;i++)
		for(int j=1;j<i;j++)
			q.push(dist[i][j]);
	for(int i=1;i<k;i++)	q.pop();
	cout<<q.top()<<endl;
}//