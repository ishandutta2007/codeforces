#include<bits/stdc++.h>
#define ll long long
#define N 300005

int n,m,a[N];

int hd[N],_hd;
struct edge{
	int v,w,nxt;
}e[N<<1];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

int fa[N],son[N],sz[N];
ll dep[N];
inline void dfs1(int u){
	sz[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(v==fa[u])
			continue;
		fa[v]=u;
		dep[v]=dep[u]+w;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])
			son[u]=v;
	}
}
int dfn[N],_dfn,top[N];
inline void dfs2(int u){
	dfn[u]=++_dfn;
	top[u]=u==son[fa[u]]?top[fa[u]]:u;
	if(son[u])
		dfs2(son[u]);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u]||v==son[u])
			continue;
		dfs2(v);
	}
}

ll S[N];

int mx;

struct node{
	ll sum,add;
	int son[2];
}t[(int)3.1e7];
int _t,rt[N];
inline int add(int q,int L,int R,int l,int r,ll d){
	if(L>r||R<l)
		return q;
	int p=q;
	if(p<=mx)
		p=++_t;
	t[p]=t[q];
	if(l<=L&&R<=r){
		t[p].add+=d;
		return p;
	}
	t[p].sum+=d*(S[std::min(R,r)]-S[std::max(L,l)-1]);
	int mid=(L+R)>>1;
	t[p].son[0]=add(t[q].son[0],L,mid,l,r,d);
	t[p].son[1]=add(t[q].son[1],mid+1,R,l,r,d);
	return p;
}
inline ll sum(int p,int L,int R,int l,int r){
	if(!p||L>r||R<l)
		return 0;
	ll res=t[p].add*(S[std::min(R,r)]-S[std::max(L,l)-1]);
	if(l<=L&&R<=r)
		return res+t[p].sum;
	int mid=(L+R)>>1;
	return res+sum(t[p].son[0],L,mid,l,r)+sum(t[p].son[1],mid+1,R,l,r);
}

inline void Add(int i,int u){
	mx=_t;
	while(u){
		rt[i]=add(rt[i],1,n,dfn[top[u]],dfn[u],1);
		u=fa[top[u]];
	}
}
inline ll Sum(int i,int u){
	ll res=0;
	while(u){
		res+=sum(rt[i],1,n,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	return res;
}

ll s[N];
inline void build(){
	_t=0;
	for(int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		Add(i,a[i]);
		s[i]=s[i-1]+dep[a[i]];
	}
}

ll ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w),addedge(v,u,w);
	}
	dfs1(1),dfs2(1);
	for(int i=1;i<=n;i++)
		S[dfn[i]]=dep[i]-dep[fa[i]];
	for(int i=1;i<=n;i++)
		S[i]+=S[i-1];
	build();
	while(m--){
		int opt,x,l,r;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&l,&r,&x);
			l^=ans,r^=ans,x^=ans;
			ans=s[r]-s[l-1]+dep[x]*(r-l+1)-2*(Sum(r,x)-Sum(l-1,x));
			printf("%lld\n",ans);
			ans&=(1<<30)-1;
		}
		else{
			scanf("%d",&x);
			x^=ans;
			if(_t>3e7)
				build();
			std::swap(a[x],a[x+1]);
			rt[x]=rt[x-1];
			Add(x,a[x]);
			s[x]=s[x-1]+dep[a[x]];
		}
	}
}