#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define N 200005
#define M 500005

int n,q;

char str[M];
std::vector<int> s[N];

namespace ACAM{
	struct node{
		node *fa,*ch[26];
	}t[M],*rt=t+1,*pos[N];
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
	inline void add(std::vector<int> &s);
	inline ll sch(std::vector<int> &s);
	inline void init();
}

namespace BIT{
	ll t[M];
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
}

namespace T{
	int hd[M],_hd;
	struct edge{
		int v,nxt;
	}e[M];
	inline void addedge(int u,int v){
		e[++_hd]=(edge){v,hd[u]};
		hd[u]=_hd;
	}
	
	int dfn[M],_dfn,sz[N];
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

inline void ACAM::add(std::vector<int> &s){
	node *u=rt;
	for(auto c:s){
		u=u->ch[c];
		BIT::add(T::dfn[id(u)],1);
	}
}
inline void ACAM::init(){
	for(int i=2;i<=_t;i++)
		T::addedge(id(t[i].fa),i);
	T::dfs(1);
}

struct node{
	int x,k,id,tp;
}qry[M<<1];
int tot;
inline bool cmp(node x,node y){
	return x.x!=y.x?x.x<y.x:x.id<y.id;
}

int ans[M];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		int len=strlen(str+1);
		for(int j=1;j<=len;j++)
			s[i].push_back(str[j]-'a');
		ACAM::pos[i]=ACAM::ins(s[i]);
	}
	ACAM::build();
	ACAM::init();
	for(int i=1;i<=q;i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		qry[++tot]=(node){l-1,k,i,-1};
		qry[++tot]=(node){r,k,i,1};
	}
	std::sort(qry+1,qry+tot+1,cmp);
	for(int i=1,r=0;i<=tot;i++){
		while(r<qry[i].x)
			ACAM::add(s[++r]);
		int u=id(ACAM::pos[qry[i].k]);
		ans[qry[i].id]+=qry[i].tp*(BIT::sum(T::dfn[u]+T::sz[u]-1)-BIT::sum(T::dfn[u]-1));
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}