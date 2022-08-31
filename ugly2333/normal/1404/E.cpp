//CF1404E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int M = 222;
const int inf = 1e9;
struct edge{
	int pr;
	int to;
	int cap;
}e[1111111];
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
	if(!x||!y)
		return;
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
int n,m,w,p,s,t,a[M][M],b[M][M],c[M][M];
char ch[M];
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		for(j=1;j<=m;j=j+1)
			a[i][j]=ch[j]=='#',p+=a[i][j];
	}
	s=1,t=2,w=2;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1){
			if(a[i][j]&&a[i][j+1])
				b[i][j]=++w,addf(s,w,1);
			if(a[i][j]&&a[i+1][j])
				c[i][j]=++w,addf(w,t,1);
		}
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1){
			addf(b[i][j],c[i][j],1);
			addf(b[i][j],c[i][j+1],1);
			addf(b[i+1][j],c[i][j],1);
			addf(b[i+1][j],c[i][j+1],1);
		}
	}
	printf("%d\n",p-((w-2)-maxflow(s,t)));
	return 0;
}