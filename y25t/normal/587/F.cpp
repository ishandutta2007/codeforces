#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define N 100005
#define B 333

int n,q;

char str[N];
std::vector<int> s[N];

namespace ACAM{
	struct node{
		node *fa,*ch[26];
	}t[N],*rt=t+1,*pos[N];
	int _t=1;
	#define id(p) (p-ACAM::t)
	inline node *ins(std::vector<int> &s){
		node *u=rt;
		for(auto c:s){
			if(!u->ch[c])
				u->ch[c]=t+(++_t);
			u=u->ch[c];
		}
		return u;
	}
	std::queue<node*> q;
	inline void build(){
		for(int i=0;i<26;i++)
			if(rt->ch[i]){
				q.push(rt->ch[i]);
				rt->ch[i]->fa=rt;
			}
			else
				rt->ch[i]=rt;
		while(q.size()){
			node *u=q.front();
			q.pop();
			for(int i=0;i<26;i++)
				if(u->ch[i]){
					u->ch[i]->fa=u->fa->ch[i];
					q.push(u->ch[i]);
				}
				else
					u->ch[i]=u->fa->ch[i];
		}
	}
	inline void init();
	inline ll sch(std::vector<int> &s);
	ll val[N];
	inline void add(std::vector<int> &s);
}
using ACAM::pos;
using ACAM::ins;
using ACAM::build;
using ACAM::init;
using ACAM::val;

namespace BIT{
	ll t[N];
	inline int lb(int x){
		return x&-x;
	}
	inline void add(int x,int d){
		for(;x<=ACAM::_t;x+=lb(x))
			t[x]+=d;
	}
	inline ll sum(int x){
		if(!x)
			return 0;
		ll res=0;
		for(;x;x-=lb(x))
			res+=t[x];
			return res;
	}
	inline void cl(){
		for(int i=1;i<=ACAM::_t;i++)
			t[i]=0;
	}
}
using BIT::add;
using BIT::sum;

namespace T{
	int hd[N],_hd;
	struct edge{
		int v,nxt;
	}e[N];
	inline void addedge(int u,int v){
		e[++_hd]=(edge){v,hd[u]};
		hd[u]=_hd;
	}
	
	int dfn[N],_dfn,sz[N];
	inline void dfs(int u){
		dfn[u]=++_dfn;
		sz[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			dfs(v);
			sz[u]+=sz[v];
		}
	}
}
using T::dfn;
using T::sz;

inline void ACAM::init(){
	for(int i=2;i<=_t;i++)
		T::addedge(id(t[i].fa),i);
	T::dfs(1);
}
inline ll ACAM::sch(std::vector<int> &s){
	ll res=0;
	node *u=rt;
	for(auto c:s){
		u=u->ch[c];
		res+=sum(dfn[id(u)]);
	}
	return res;
}
inline void ACAM::add(std::vector<int> &s){
	BIT::cl();
	node *u=rt;
	for(auto c:s){
		u=u->ch[c];
		BIT::add(dfn[id(u)],1);
	}
	for(int i=1;i<=n;i++){
		int u=id(pos[i]);
		val[i]=val[i-1]+sum(dfn[u]+sz[u]-1)-sum(dfn[u]-1);
	}
}

ll ans[N];

namespace SOL1{
	struct node{
		int x,k,id,tp;
	}qry[N<<1];
	int tot;
	inline bool cmp(node x,node y){
		return x.x!=y.x?x.x<y.x:x.id<y.id;
	}
	
	inline void ins(int l,int r,int k,int id){
		qry[++tot]=(node){l-1,k,id,-1};
		qry[++tot]=(node){r,k,id,1};
	}
	
	inline void sol(){
		std::sort(qry+1,qry+tot+1,cmp);
		for(int i=1,r=0;i<=tot;i++){
			while(r<qry[i].x){
				int u=id(pos[++r]);
				add(dfn[u],1);
				add(dfn[u]+sz[u],-1);
			}
			ans[qry[i].id]+=qry[i].tp*ACAM::sch(s[qry[i].k]);
		}
	}
}

namespace SOL2{
	struct node{
		int l,r,k,id;
	}qry[N];
	int tot;
	inline bool cmp(node x,node y){
		return x.k!=y.k?x.k<y.k:x.id<y.id;
	}
	
	inline void ins(int l,int r,int k,int id){
		qry[++tot]=(node){l,r,k,id};
	}
	
	inline void sol(){
		std::sort(qry+1,qry+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			if(qry[i].k!=qry[i-1].k)
				ACAM::add(s[qry[i].k]);
			ans[qry[i].id]=val[qry[i].r]-val[qry[i].l-1];
		}
	}
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		int len=strlen(str+1);
		for(int j=1;j<=len;j++)
			s[i].push_back(str[j]-'a');
		pos[i]=ins(s[i]);
	}
	build();
	init();
	for(int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(s[k].size()<=B)
			SOL1::ins(l,r,k,i);
		else
			SOL2::ins(l,r,k,i);
	}
	SOL1::sol();
	SOL2::sol();
	for(int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
}