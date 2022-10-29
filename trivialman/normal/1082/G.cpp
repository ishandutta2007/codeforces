#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 8500;
const LL inf = 1e18;
int to[N],nxt[N],head[N],dis[N],vd[N];
LL cap[N], flow, sum, c;
int n,m,tot=1,S,T,u,v,x;

void add(int x,int y,LL z){
	to[++tot]=y,cap[tot]=z,nxt[tot]=head[x],head[x]=tot;
	to[++tot]=x,cap[tot]=0,nxt[tot]=head[y],head[y]=tot;
}

LL sap(int u, LL flow){
	if(flow==0||u==T) return flow;
	LL tmp, delta=0;
	for(int i=head[u];i;i=nxt[i]){
		if(dis[u]==dis[to[i]]+1 && cap[i]>0){
			tmp = sap(to[i], min(cap[i],flow-delta));
			delta+=tmp, cap[i]-=tmp, cap[i^1]+=tmp;
			if(delta==flow||dis[S]>T+1) return delta;
		}
	}
	vd[dis[u]]--;
	if(vd[dis[u]]==0)dis[S]=T+2;
	vd[++dis[u]]++;
	return delta;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	S=0; T=n+m+1;
	rep(i,1,n)scanf("%d",&x),add(m+i,T,x);
	rep(i,1,m){
		scanf("%d%d%lld",&u,&v,&c);
		sum += c;
		add(S,i,c), add(i,m+u,inf), add(i,m+v,inf);
	}
	while(dis[S]<=T) flow+=sap(S,inf);
	printf("%lld\n",sum-flow);
	return 0;
}