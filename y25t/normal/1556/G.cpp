#include<bits/stdc++.h>
#define ll long long
#define M 50005

int n,m;

char str[M];
std::pair<ll,ll> q[M];

std::vector<std::pair<int,int>> E[M];

struct node{
	int id,col;
	node *son[2];
	node(int id_=0){
		id=id_;
		col=0;
		son[0]=son[1]=0;
	}
	inline bool lf(){
		return !son[0];
	}
}*rt;
int tot;
inline void pshd(node *p){
	if(!p->son[0])
		p->son[0]=new node(++tot);
	if(!p->son[1])
		p->son[1]=new node(++tot);
	if(p->col){
		p->son[0]->col=p->son[1]->col=p->col;
		p->col=0;
	}
}
inline void ins(node *p,ll L,ll R,ll l,ll r,int t){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		p->col=t;
		return;
	}
	pshd(p);
	ll mid=(L+R)>>1;
	ins(p->son[0],L,mid,l,r,t);
	ins(p->son[1],mid+1,R,l,r,t);
}
inline void sol(node *x,node *y){
	if(x->lf()&&y->lf()){
		E[std::min(x->col,y->col)].push_back({x->id,y->id});
		return;
	}
	sol(x->lf()?x:x->son[0],y->lf()?y:y->son[0]);
	sol(x->lf()?x:x->son[1],y->lf()?y:y->son[1]);
}
inline void dfs(node *p){
	if(p->lf())
		return;
	sol(p->son[0],p->son[1]);
	dfs(p->son[0]),dfs(p->son[1]);
}
inline node *pos(node *p,ll L,ll R,ll x){
	if(p->lf())
		return p;
	ll mid=(L+R)>>1;
	if(x<=mid)
		return pos(p->son[0],L,mid,x);
	else
		return pos(p->son[1],mid+1,R,x);
}

int f[M<<8];
inline int fnd(int x){
	return ~f[x]?f[x]=fnd(f[x]):x;
}
inline void mrg(int u,int v){
	if(fnd(u)!=fnd(v))
		f[fnd(u)]=fnd(v);
}

int ans[M];

int main(){
	scanf("%d%d",&n,&m);
	rt=new node(++tot);
	rt->col=m+1;
	for(int i=1;i<=m+1;i++)
		q[i]={-1,-1};
	for(int i=1;i<=m;i++){
		ll u,v;
		scanf("%s%lld%lld",str,&u,&v);
		if(str[0]=='a')
			q[i]={u,v};
		else
			ins(rt,0,(1ll<<n)-1,u,v,i);
	}
	dfs(rt);
	memset(f,-1,sizeof(f));
	for(int i=m+1;i;i--){
		for(auto [u,v]:E[i])
			mrg(u,v);
		auto [u,v]=q[i];
		if(~u)
			ans[i]=fnd(pos(rt,0,(1ll<<n)-1,u)->id)==fnd(pos(rt,0,(1ll<<n)-1,v)->id);
	}
	for(int i=1;i<=m;i++)
		if(~q[i].first)
			printf("%d\n",ans[i]);
}