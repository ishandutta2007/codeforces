//CF 103E
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
const int N = 666;
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

int vis[N],w[N];
bool hungary(int x){
	int i,y;
	for(i=la[x];i;i=e[i].pr){
		y=e[i].to;
		if(!vis[y]){
			vis[y]=1;
			if(!w[y]||hungary(w[y])){
				w[y]=x;
				return true;
			}
		}
	}
	return false;
}
int n,a[N][N];
int main(){
	int i,j,o,s,t,ans;
	scanf("%d",&n);
	clr();
	for(i=1;i<=n;i=i+1){
		scanf("%d",&o);
		while(o--){
			scanf("%d",&j);
			a[i][j]=1;
			adde(i,j,0);
		}
	}
	for(i=1;i<=n;i=i+1){
		memset(vis,0,sizeof(vis));
		hungary(i);
	}
	clr();
	s=0,t=n+1;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(a[i][j])
				addf(i,w[j]);
	ans=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&o);
		if(o>0)
			addf(i,t,o);
		else{
			ans+=o;
			addf(s,i,-o);
		}
	}
	printf("%d",ans+maxflow(s,t));
	return 0;
}