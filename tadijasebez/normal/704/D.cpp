#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
const int ESZ=500050;
const int NSZ=100050;
const int inf=1e9;
void ckmn(int &a,int b){ a=min(a,b);}
struct Dinic{
	int n,s,t,xb,cb[NSZ<<1],ds[NSZ<<1];
	struct Edge{int u,v,f,c;}edges[ESZ<<1];
	vi E[NSZ<<1];
	void Clear(){
		for(int i=1;i<=n;i++)E[i].clear();
		xb=s=t=n=0;
	}
	void Reset(){
		for(int i=0;i<xb;i++)edges[i].f=0;
	}
	void AddEdge(int u,int v,int c){
		E[u].pb(xb);edges[xb++]=(Edge){u,v,0,c};
		E[v].pb(xb);edges[xb++]=(Edge){v,u,0,0};
	}
	int Cut(int u,int f){
		if(!f || ds[u]>ds[t])return 0;
		if(u==t)return f;
		int ans=0;
		for(;cb[u]<E[u].size();cb[u]++){
			int e=E[u][cb[u]],v,c;tie(v,c)=(pii){edges[e].v,edges[e].c-edges[e].f};
			if(!c || ds[v]!=ds[u]+1)continue;
			int ct=Cut(v,min(f,c));
			f-=ct;ans+=ct;edges[e].f+=ct;edges[e^1].f-=ct;
			if(!f)return ans;
		}
		return ans;
	}
	int q[NSZ<<1],ql,qr;
	bool BFS(){
		for(int i=1;i<=n;i++)ds[i]=inf,cb[i]=0;
		ql=qr=0;q[qr++]=s;ds[s]=0;
		while(ql<qr){
			int u=q[ql++];
			for(int e:E[u]){
				int v,c;tie(v,c)=(pii){edges[e].v,edges[e].c-edges[e].f};
				if(c && ds[v]>ds[u]+1){
					ds[v]=ds[u]+1;q[qr++]=v;
				}
			}
		}
		return ds[t]!=inf;
	}
	int MaxFlow(){
		int ans=0;
		while(BFS())ans+=Cut(s,inf);
		return ans;
	}
};
struct LRMaxFlow{
	int n,s,t,xb,bl[NSZ<<1],mao[NSZ<<1],guo[NSZ*3],chk=1;
	struct Edge{int u,v,l,r;}edges[NSZ*3];
	void AddEdge(int u,int v,int l,int r){
		edges[xb++]=(Edge){u,v,l,r};
		bl[u]-=l;bl[v]+=l;chk&=l<=r;
	}
	Dinic fn;
	void MaxFlow(){
		fn.n=n+2;fn.s=n+1;fn.t=n+2;
		for(int i=0;i<xb;i++)fn.AddEdge(edges[i].u,edges[i].v,edges[i].r-edges[i].l),guo[i+1]=fn.xb-2;
		for(int i=1;i<=n;i++){
			if(bl[i]>0)fn.AddEdge(fn.s,i,bl[i]);
			else fn.AddEdge(i,fn.t,-bl[i]);
			mao[i]=fn.xb-2;
		}
		fn.MaxFlow();
		for(int i=1;i<=n;i++)chk&=fn.edges[mao[i]].f==fn.edges[mao[i]].c;
		fn.s=s;fn.t=t;
		fn.MaxFlow();
	}
	int Use(int i){return fn.edges[guo[i]].f;}
}fn;
int x[NSZ],y[NSZ],xsz,ysz,dgx[NSZ],dgy[NSZ],lmx[NSZ],lmy[NSZ];
map<int,int> idx,idy;
int main(){
	int n,m,r,b;
	scanf("%i %i %i %i",&n,&m,&r,&b);
	for(int i=1;i<=n;i++){
		scanf("%i %i",&x[i],&y[i]);
		if(!idx[x[i]])idx[x[i]]=++xsz;
		if(!idy[y[i]])idy[y[i]]=++ysz;
		x[i]=idx[x[i]];dgx[x[i]]++;
		y[i]=idy[y[i]];dgy[y[i]]++;
	}
	for(int i=1;i<=xsz;i++)lmx[i]=dgx[i];
	for(int i=1;i<=ysz;i++)lmy[i]=dgy[i];
	fn.n=xsz+ysz+2;fn.s=fn.n-1;fn.t=fn.n;
	for(int i=1;i<=n;i++)fn.AddEdge(x[i],y[i]+xsz,0,1);
	for(int i=1;i<=m;i++){
		int t,p,l;
		scanf("%i %i %i",&t,&p,&l);
		if(t==1)ckmn(lmx[idx[p]],l);
		else ckmn(lmy[idy[p]],l);
	}
	for(int i=1;i<=xsz;i++)fn.AddEdge(fn.s,i,dgx[i]-lmx[i]+1>>1,dgx[i]+lmx[i]>>1);
	for(int i=1;i<=ysz;i++)fn.AddEdge(i+xsz,fn.t,dgy[i]-lmy[i]+1>>1,dgy[i]+lmy[i]>>1);
	fn.AddEdge(fn.t,fn.s,0,n);
	fn.MaxFlow();
	if(fn.chk){
		int ans=0;
		for(int i=1;i<=n;i++)ans+=fn.Use(i);
		printf("%lld\n",(ll)ans*min(r,b)+(ll)(n-ans)*max(r,b));
		for(int i=1;i<=n;i++)printf("%c",(fn.Use(i)^(r<b))?'b':'r');
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}