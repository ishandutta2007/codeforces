//CF1615H
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1111;
const int inf = 1e9;
struct edge{
	int pr;
	int to;
	int cap;
}e[111111];
int tot=1,la[N];
void clr(){
	tot=1;
	memset(la,0,sizeof(la));
}
void adde(int x,int y,int z){
	e[++tot].pr=la[x];
	la[x]=tot;
	e[tot].to=y;
	e[tot].cap=z;
}
void addf(int x,int y,int z=inf){
	adde(x,y,z);
	adde(y,x,0);
}
int d[N];
int bfs(int s,int t){
	queue<int> Q;
	int i,x,y;
	memset(d,0,sizeof(d));
	d[s]=1;
	Q.push(s);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=la[x];i;i=e[i].pr){
			if(!e[i].cap)
				continue;
			y=e[i].to;
			if(!d[y]){
				d[y]=d[x]+1;
				Q.push(y);
			}
		}
	}
	return d[t];
}
int dfs(int s,int t,int f){
	if(s==t)
		return f;
	int i,x,y,r=0;
	for(i=la[s];i;i=e[i].pr){
		if(!e[i].cap||!f)
			continue;
		y=e[i].to;
		if(d[y]!=d[s]+1)
			continue;
		x=dfs(y,t,min(f,e[i].cap));
		if(x){
			f-=x;
			r+=x;
			e[i].cap-=x;
			e[i^1].cap+=x;
		}
	}
	if(!r)
		d[s]=0;
	return r;
}
int maxflow(int s,int t){
	int x,r=0;
	while(bfs(s,t)){
		x=dfs(s,t,inf);
		if(x)
			r+=x;
		else
			break;
	}
	return r;
}
int n,m,a[N],b[N],c[N],g[N],ss,tt;
vector<int> v[N];
pair<int,int> p[N];
LL s;
int go(int u,int t){
	if(u==t)
		return 1;
	d[u]=1;
	int i,x;
	for(i=la[u];i;i=e[i].pr){
		if(!e[i].cap)
			continue;
		x=e[i].to;
		if(!d[x]&&go(x,t)){
			e[i].cap--;
			e[i^1].cap++;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int i,j,k,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),p[i]=make_pair(a[i],i);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
	}
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++)
		s+=a[i]-p[1].first,c[i]=1;
	x=p[1].first;
	clr();
	ss=n+1,tt=n+2;
	for(j=1;j<=n;j++){
		if(!b[j]){
			if(c[j]==1)
				addf(ss,j,1),g[j]=tot-1;
			else
				addf(j,tt,1),g[j]=tot-1;
			for(k=0;k<v[j].size();k++)
				addf(j,v[j][k]);
			z++;
		}
	}
	for(i=1;i<n;i++){
		j=p[i].second;
		c[j]=-1;
		if(!e[g[j]].cap){
			memset(d,0,sizeof(d));
			go(tt,j);
		}
		e[g[j]].cap=0,e[g[j]^1].cap=0;
		addf(j,tt,1),g[j]=tot-1;
		maxflow(ss,tt);
		bfs(ss,tt);
		for(j=1;j<=n;j++){
			if(!b[j]){
				if(!d[j]){
					b[j]=p[i].first;
				}
			}
		}
	}
	for(j=1;j<=n;j++)
		if(!b[j])
			b[j]=p[n].first;
	for(i=1;i<=n;i++)
		printf("%d ",b[i]);
	return 0;
}