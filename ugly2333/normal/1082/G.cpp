//CF1082G
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
const int N = 2222;
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
LL dfs(int s,int t,int f){
	if(s==t)
		return f;
	int i,x,y;
	LL r=0;
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
LL maxflow(int s,int t){
	LL x,r=0;
	while(bfs(s,t)){
		x=dfs(s,t,inf);
		if(x)
			r+=x;
		else
			break;
	}
	return r;
}
int n,m,s,t;
int main()
{
	int i,x,y,z;
	LL ans=0;
	cin>>n>>m;
	s=n+m+1,t=s+1;
	for(i=1;i<=n;i=i+1){
		cin>>z;
		addf(s,i,z);
	}
	for(i=n+1;i<=n+m;i=i+1){
		cin>>x>>y>>z;
		addf(x,i);
		addf(y,i);
		addf(i,t,z);
		ans+=z;
	}
	cout<<ans-maxflow(s,t);
	return 0;
}