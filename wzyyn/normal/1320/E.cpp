#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
vector<int> e[N];
int n,fa[N],sz[N],dep[N];
int dfn[N],ed[N],top[N];
void dfs1(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs1(i);
			sz[x]+=sz[i];
		}
}
void dfs2(int x,int tp){
	//cout<<x<<' '<<tp<<' '<<dep[x]<<endl;
	top[x]=tp;
	dfn[x]=++*dfn;
	int k=0;
	for (auto i:e[x])
		if (i!=fa[x]&&sz[i]>sz[k])
			k=i;
	if (k) dfs2(k,tp);
	for (auto i:e[x])
		if (i!=fa[x]&&i!=k)
			dfs2(i,i);
	ed[x]=*dfn; 
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}


int head[N],vis[N],tot,P,Q;
int p1[N],p2[N],q[N*2],v[N];
struct edge{
	int to,next,v;
}E[N*2];
struct info{
	int id,T,rem;
	bool operator <(const info &a)const{
		if (T!=a.T) return T<a.T;
		if (id!=a.id) return id<a.id;
		return rem<a.rem;
	} 
}dis[N];
struct node{
	info t;
	int id;
	bool operator <(const node &a)const{
		return !(t<a.t);
	} 
};
priority_queue<node> QQ; 
void add(int x,int y){
	//cout<<"ADDE "<<x<<' '<<y<<endl;
	E[++tot]=(edge){y,head[x],dep[y]-dep[x]};
	head[x]=tot;
	E[++tot]=(edge){x,head[y],dep[y]-dep[x]};
	head[y]=tot;
}

void solve(){
	*q=0;
	scanf("%d%d",&P,&Q);
	For(i,1,P) scanf("%d%d",&p1[i],&v[i]),q[++*q]=p1[i];
	For(i,1,Q) scanf("%d",&p2[i]),q[++*q]=p2[i];
	sort(q+1,q+*q+1,cmp);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,(*q)-1) q[i+(*q)]=LCA(q[i],q[i+1]);
	sort(q+1,q+2*(*q),cmp);
	*q=unique(q+1,q+2*(*q))-q-1;
	For(i,1,*q) vis[q[i]]=head[q[i]]=0;
	For(i,1,*q) dis[q[i]]=(info){0,1<<30,1<<30};
	int top=1; tot=0;
	For(i,2,*q){
		for (;!isfa(q[top],q[i]);--top);
		add(q[top],q[i]);
		q[++top]=q[i];
	}
	for (;!QQ.empty();QQ.pop());
	For(i,1,P){
		dis[p1[i]]=(info){i,-1,v[i]};
		QQ.push((node){dis[p1[i]],p1[i]});
	}
	while (!QQ.empty()){
		int x=QQ.top().id; QQ.pop();
		if (vis[x]) continue;
		vis[x]=1;
		//cout<<x<<' '<<dis[x].id<<endl;
		for (int i=head[x];i;i=E[i].next){
			int d=dis[x].T*v[dis[x].id]+dis[x].rem+E[i].v;
			info tmp=(info){dis[x].id,(d-1)/v[dis[x].id],(d-1)%(v[dis[x].id])+1};
			if (tmp<dis[E[i].to]){
				dis[E[i].to]=tmp;
				QQ.push((node){tmp,E[i].to});
			}
		}
	}
	For(i,1,Q)
		printf("%d ",dis[p2[i]].id);
	puts("");
}
//info:{,,}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs1(1);
	dfs2(1,1);
	int Q;
	scanf("%d",&Q);
	while (Q--) solve();
}