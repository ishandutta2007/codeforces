//CF 164C
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
const int N = 4444;
const int inf = 2e9;
struct edge{
	int to;
	int pr;
	int c;
	int w;
}e[N<<1];
int tot=1,la[N];
void adde(int x,int y,int z,int h){
	e[++tot].pr=la[x];
	la[x]=tot;
	e[tot].to=y;
	e[tot].c=z;
	e[tot].w=h;
}
void addf(int x,int y,int z,int h){
	adde(x,y,z,h);
	adde(y,x,0,-h);
}
int n,k,s[N],t[N],a[N],ans[N];
map<int,int> M;
map<int,int>::iterator it;
int m,p[N],d[N],f[N],vis[N];
priority_queue<pair<int,int> > Q;
void mcf(){
	int i,x,y,z;
	d[1]=0;
	Q.push(make_pair(0,1));
	while(!Q.empty()){
		x=Q.top().second;
		Q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(i=la[x];i;i=e[i].pr){
			if(!e[i].c)
				continue;
			y=e[i].to;
			z=e[i].w+p[x]-p[y];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				f[y]=i;
				Q.push(make_pair(-d[y],y));
			}
		}
	}
	if(!vis[m])
		return;
	x=m;
	while(f[x]){
		i=f[x]^1;
		e[i^1].c--;
		e[i].c++;
		x=e[i].to;
		ans[i>>1]=i&1;
	}
	for(i=1;i<=m;i=i+1)
		p[i]+=d[i];
}
int main()
{
	int i,o,x,y,z;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",s+i,t+i,a+i);
		t[i]+=s[i];
		M[s[i]]=1;
		M[t[i]]=1;
	}
	for(it=M.begin();it!=M.end();it++)
		M[(*it).first]=++m;
	for(i=1;i<=n;i=i+1){
		s[i]=M[s[i]];
		t[i]=M[t[i]];
		addf(s[i],t[i],1,-a[i]);
	}
	for(i=1;i<m;i=i+1)
		addf(i,i+1,inf,0);
	
	do{
		o=0;
		for(x=1;x<=m;x=x+1)
			for(i=la[x];i;i=e[i].pr){
				if(!e[i].c)
					continue;
				y=e[i].to;
				z=e[i].w;
				if(p[y]>p[x]+z){
					p[y]=p[x]+z;
					o=1;
				}
			}
	}while(o);
	
	while(k--){
		for(i=1;i<=m;i=i+1)
			d[i]=inf;
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		mcf();
	}
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}