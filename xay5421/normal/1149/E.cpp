#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
const int N=200005;typedef long long ll;
int n,m,t=-1,he,ta,sg[N],d[N],s[N],q[N];bool vis[N];ll h[N];
struct ed{ed*nxt;int to;}pool[N],*p=pool,*lnk[N];
void ae(int u,int v){*++p=(ed){lnk[u],v},++d[v],lnk[u]=p;}
void dfs(int u){
	
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",h+i);
	rep(i,1,m){int u,v;scanf("%d%d",&u,&v);ae(u,v);}
	rep(i,1,n)if(!d[i])q[++ta]=i;
	while(he!=ta){
		int u=q[++he];
		for(ed*i=lnk[u];i;i=i->nxt)if(!--d[i->to])q[++ta]=i->to;
	}
	per(i,n,1){
		int u=q[i];
		for(ed*i=lnk[u];i;i=i->nxt)vis[sg[i->to]]=1;
		while(vis[sg[u]])++sg[u];
		for(ed*i=lnk[u];i;i=i->nxt)vis[sg[i->to]]=0;
		s[sg[u]]^=h[u];
	}
	rep(i,0,n)if(s[i])t=i;
	if(t==-1)return 0&puts("LOSE");
	rep(i,1,n){
		if(sg[i]==t&&((h[i]^s[t])<h[i])){
			h[i]^=s[t];
			for(ed*j=lnk[i];j;j=j->nxt){
				h[j->to]^=s[sg[j->to]];
				s[sg[j->to]]=0;
			}
			break;
		}
	}
	puts("WIN");rep(i,1,n)printf("%lld ",h[i]);
	return 0;
}