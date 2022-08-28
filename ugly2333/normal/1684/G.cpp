//CF1684G
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
const int N = 1111;
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
int n,m,a[N];
vector<int> v1,v2;
void ins(int x,int y){
	v1.push_back(x);
	v2.push_back(y);
}
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	x=0;
	for(i=1;i<=n;i++){
		if(a[i]*2>m-a[i]){
			x++;
			for(j=1;j<=n;j++)
				if(a[i]*2<=m-a[j]&&a[i]%a[j]==0)
					addf(i,j);
			addf(0,i,1);
		}
		else
			addf(i,n+1,1);
	}
	if(maxflow(0,n+1)!=x){
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++){
		if(a[i]*2<=m-a[i]){
			for(j=la[i];j;j=e[j].pr){
				if(e[j].cap){
					x=e[j].to;
					if(x==n+1)
						ins(a[i]*3,a[i]*2);
					else
						ins(a[x]*2+a[i],a[x]+a[i]);
				}
			}
		}
	}
	printf("%d\n",v1.size());
	for(i=0;i<v1.size();i++)
		printf("%d %d\n",v1[i],v2[i]);
	return 0;
}