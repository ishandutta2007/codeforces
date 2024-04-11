#include<stdio.h>
#include<math.h>
#define inf 1000000000
const int maxn=200005,maxm=maxn<<1;
int n,e,stp,minn,pos,ans;
int v[maxn],start[maxn],to[maxm],then[maxm],worth[maxm],vis[maxn],size[maxn],fin[maxn];
double val,all,now;
double tot[maxn];
inline int max(int a,int b){
	return a>b? a:b;
}
inline void add(int x,int y,int z){
	then[++e]=start[x],start[x]=e,to[e]=y,worth[e]=z;
}
void find(int x,int sum){
	int maxx=0;
	vis[x]=stp,size[x]=1;
	for(int i=start[x];i;i=then[i])
		if(fin[to[i]]==0&&vis[to[i]]!=stp)
			find(to[i],sum),size[x]+=size[to[i]],maxx=max(maxx,size[to[i]]);
	maxx=max(maxx,sum-size[x]);
	if(maxx<minn)
		minn=maxx,pos=x;
}
void dfs(int x,int last,int dis,int top){
	now+=1.0*v[x]*dis*sqrt(dis),all+=1.5*v[x]*sqrt(dis),tot[top]+=1.5*v[x]*sqrt(dis);
	for(int i=start[x];i;i=then[i])
		if(to[i]!=last)
			dfs(to[i],x,dis+worth[i],top);
}
void solve(int x,int sum){
	stp++,minn=inf,find(x,sum),x=pos,fin[x]=1;
	all=now=0;
	for(int i=start[x];i;i=then[i])
		tot[to[i]]=0,dfs(to[i],x,worth[i],to[i]);
	if(now<val)
		val=now,ans=x;
	find(x,sum);
	for(int i=start[x];i;i=then[i])
		if(fin[to[i]]==0&&all-2*tot[to[i]]<0){
			solve(to[i],size[to[i]]);
			break;
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	val=1e30,solve(1,n);
	printf("%d %.10lf\n",ans,val);
	return 0;
}