#include<bits/stdc++.h>

#define DEBUG(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

const int N=1005,M=30005;

int h[N],nxt[M<<1],to[M<<1],tmp=1,cost[M<<1],fa[N],n,m,s,t,res,ans=0x7FFFFFFF;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool del[M<<1],vis[N];
void addedge(int u,int v,int c){
	to[++tmp]=v,nxt[tmp]=h[u],h[u]=tmp,cost[tmp]=c;
	to[++tmp]=u,nxt[tmp]=h[v],h[v]=tmp,cost[tmp]=c;
}

vector<int>B[N],eid,stk,ae,ne;
int dfn[N],low[N],dfc,bcc,st[N],tp,in[N];

void tarjan(int x,int fb){
	st[++tp]=x,low[x]=dfn[x]=++dfc;
	for(int i=h[x];i;i=nxt[i])if(!del[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v,i^1);
			low[x]=min(low[x],low[v]);
			if(low[v]>dfn[x]){
				bcc++;
				int p=0;
				while(p!=v){
					B[bcc].push_back(p=st[tp]);
					in[p]=bcc,st[tp--]=0;
				}
			}
		}else if(i!=fb)low[x]=min(low[x],low[v]);
	}
	if(!fb){
		bcc++;
		while(tp){
			B[bcc].push_back(st[tp]);
			in[st[tp]]=bcc,st[tp--]=0;
		}
	}
}

void dfs(int x,int&cur){
//	DEBUG("in %d\n",x);
	vis[x]=true;
	if(x==in[t])return;
	for(int u:B[x]){
		for(int i=h[u],v;i;i=nxt[i])if(!del[i]){
			v=to[i];
			if(vis[in[v]]) continue;
			dfs(in[v],cur);
			if(vis[in[t]]){
//				DEBUG("%d : %d\n",x,i>>1);
				if(!cur||cost[i]<cost[cur])cur=i;
				return;
			}
		}
	}
//	DEBUG("out %d\n",x);
}

void check(){
	memset(dfn,0,n+1<<2),memset(low,0,n+1<<2),memset(in,0,n+1<<2),memset(vis,0,n+1);
	while(bcc)vis[bcc]=false,B[bcc--].clear();dfc=0;
	tarjan(s,0);
//	for(int i=1;i<=n;i++)DEBUG("%d in block %d\n",i,in[i]);
	if(!dfn[t]){
		if(ans>res)ans=res,ae=ne;
		return;
	}
	if(in[s]==in[t])return;
	int cur=0;
	dfs(in[s],cur);
	if(cost[cur]+res<ans){
		ans=cost[cur]+res;
		ae=ne;ae.push_back(cur>>1);
	}
}

void dfs(int x){
	vis[x]=true;
	if(x==t){eid=stk;return;}
	if(eid.size())return;
	for(int i=h[x],v;i;i=nxt[i])if(!vis[v=to[i]]){
		stk.push_back(i);
		dfs(v);
		stk.pop_back();
		if(eid.size())return;
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		int fu=find(u),fv=find(v);
		if(fu!=fv)fa[fu]=fv;
	}
	if(find(s)!=find(t))puts("0\n0"),exit(0);
	dfs(s);
	for(int p:eid){
		del[p]=del[p^1]=true,res+=cost[p],ne.push_back(p>>1);
//		DEBUG("\ndelete %d\n",p>>1);
		check();
		del[p]=del[p^1]=false,res-=cost[p],ne.pop_back();
	}
	if(ans==0x7FFFFFFF)puts("-1"),exit(0);
	printf("%d\n%d\n",ans,(int)ae.size());
	for(int p:ae)printf("%d ",p);puts("");
	return 0;
}