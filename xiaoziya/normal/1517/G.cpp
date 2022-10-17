#include<stdio.h>
#include<queue>
#include<math.h>
#define inf 1000000000
using namespace std;
const int maxn=2005,maxm=1000005;
int n,m,s,t,e=1,flg;
long long flow,sum;
int start[maxn],to[maxm],then[maxm],limit[maxm],dep[maxn],cur[maxn],vis[maxn],x[maxn],y[maxn],w[maxn],typ[maxn];
queue<int>q;
inline void add(int x,int y,int z){
	then[++e]=start[x],start[x]=e,to[e]=y,limit[e]=z;
}
inline void addedge(int x,int y,int z){
	add(x,y,z),add(y,x,0);
}
int bfs(int s){
	for(int i=1;i<=t;i++)
		vis[i]=0,dep[i]=t+1,cur[i]=start[i];
	q.push(s),vis[s]=1,dep[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop(),vis[x]=0;
		for(int i=start[x];i;i=then[i]){
			int y=to[i];
			if(limit[i]&&dep[y]>dep[x]+1){
				dep[y]=dep[x]+1;
				if(vis[y]==0)
					q.push(y),vis[y]=1;
			}
		}
	}
	return dep[t]!=t+1;
}
int dfs(int x,int flw,int t){
	if(x==t){
		flow+=flw,flg=1;
		return flw;
	}
	int rst=flw;
	for(int i=cur[x];i;i=then[i]){
		cur[x]=i;
		int y=to[i];
		if(limit[i]&&dep[y]==dep[x]+1){
			int newflw=dfs(y,min(rst,limit[i]),t);
			if(newflw){
				rst-=newflw,limit[i]-=newflw,limit[i^1]+=newflw;
				if(rst==0)
					break;
			}
			else dep[y]=0;
		}
	}
	return flw-rst;
}
long long Dinic(int s,int t){
	flow=0;
	while(bfs(s))
		for(flg=1;flg;)
			flg=0,dfs(s,1e9,t);
	return flow;
}
int main(){
	scanf("%d",&n),s=n+n+1,t=s+1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&w[i]),addedge(i,n+i,w[i]);
		if(x[i]&1)
			typ[i]=(y[i]&1)? 0:3;
		else typ[i]=(y[i]&1)? 1:2;
		sum+=w[i];
		if(typ[i]==0)
			addedge(s,i,inf);
		if(typ[i]==3)
			addedge(n+i,t,inf);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(abs(x[i]-x[j])<=1&&abs(y[i]-y[j])<=1&&typ[i]+1==typ[j])
				addedge(n+i,j,inf);
	printf("%lld\n",sum-Dinic(s,t));
	return 0;
}