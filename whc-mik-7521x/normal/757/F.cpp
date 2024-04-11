#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int n,m,s,deg[N],q[N],h,r,id[N],sz[N],ans,tmp[N];
long long dis[N];
struct node{
	long long d;
	int u;
	bool operator<(const node &b)const{return d>b.d;}
};
priority_queue<node>pq; 
struct edge{
    int w,to,nxt;
};
edge ed[N<<1];
int cnt,he[N];
void add(int st,int et,int wi){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w=wi;
    ed[cnt].nxt=he[st];
    he[st]=cnt;
}
vector<int>eg[N];
void add2(int x,int y){
	eg[x].push_back(y);deg[y]++;
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);add(y,x,w);
	}
    memset(dis,63,sizeof dis);
	pq.push((node){dis[s]=0,s});
	while(!pq.empty()){
		int u=pq.top().u;
		long long d=pq.top().d;
		pq.pop();
		if(dis[u]!=d) continue;
		for(int i=he[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			if(d+ed[i].w<dis[v]) pq.push((node){dis[v]=d+ed[i].w,v});
		}
	}
	for(int o=1;o<=n;o++){
        for(int i=he[o];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(dis[o]+ed[i].w==dis[v])add2(o,v);
        }
    }
	q[h=r=1]=s;
	for(int i=1;i<=n;i++)tmp[i]=i;
	while(h<=r){
		int u=q[h++];
		if(tmp[u]!=-1&&tmp[u]!=s)id[u]=tmp[u];
		else id[u]=u;
		sz[id[u]]++;
		for(int v:eg[u]){
			if(tmp[v]==v)tmp[v]=id[u];
			else if(tmp[v]!=id[u])tmp[v]=-1;
			if(!--deg[v])q[++r]=v;
		}
	}
	for(int i=1;i<=n;i++)if(i!=s)ans=max(ans,sz[i]);
	printf("%d\n",ans);
}