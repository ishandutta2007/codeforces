#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N=6500,M=5e4,inf=0x3f3f3f3f;
int a[85][85],ver[M],edge[M],cost[M],nxt[M],head[N],d[N],v[N],q[M*50],path[N],dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int n,m,i,j,k,tot,s,t,ans,x,y,z,l,r;
 
void add(int x,int y,int z,int w){
	ver[++tot]=y,edge[tot]=z,cost[tot]=w,nxt[tot]=head[x],head[x]=tot;
	ver[++tot]=x,edge[tot]=0,cost[tot]=-w,nxt[tot]=head[y],head[y]=tot;
}

bool spfa(){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	q[l=r=1]=s,d[s]=0,v[s]=1;
	while(l<=r){
		x=q[l++],v[x]=0;
		for(i=head[x];i;i=nxt[i])
			if(edge[i]&&d[y=ver[i]]>d[x]+cost[i]){
				d[y]=d[x]+cost[i],path[y]=i;
				if(!v[y]) q[++r]=y,v[y]=1;
			}
	}
	return d[t]!=inf;
}

void update(){
	for(y=t;y!=s;y=x){
		i=path[y],x=ver[i^1];
		--edge[i],++edge[i^1];
	}
	ans+=d[t];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>a[i][j];
	s=0,t=n*m+1,tot=1;
	rep(i,1,n)rep(j,1,m)
		if(i+j&1){
			add(s,(i-1)*m+j,1,0);
			for(k=0;k<4;k++){
				x=i+dx[k],y=j+dy[k];
				if(x<1||x>n||y<1||y>m) continue;
				add((i-1)*m+j,(x-1)*m+y,1,a[i][j]!=a[x][y]);
			}
		}
		else
			add((i-1)*m+j,t,1,0);
	while(spfa()) update();
	cout<<ans<<endl;
	return 0;
}