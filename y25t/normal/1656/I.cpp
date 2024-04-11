#include<bits/stdc++.h>
#define N 300005

int T;

int n,m;

std::vector<int> E[N];

struct node{
	int val;
	node *nxt;
	node(int x=0){
		val=x,nxt=0;
	}
};
struct L{
	node *st,*ed;
	L(node *x=0){
		st=ed=x;
	}
};
L operator + (L x,L y){
	if(!x.st||!y.st)
		return x.st?x:y;
	x.ed->nxt=y.st,x.ed=y.ed;
	return x;
}

std::vector<int> ans[N];

bool flg;

std::vector<int> A;
std::vector<std::pair<int,int>> B;
node *p[N];

int cur[N],pos[N];

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}

inline void upd(){
	if(!A.size())
		return;
	for(auto u:A)
		cur[u]=ans[u].size();
	std::vector<int> V;
	for(node *u=p[A[0]];;u=u->nxt){
		pos[u->val]=V.size(),V.emplace_back(u->val);
		if(u->nxt==p[A[0]])
			break;
	}
	int l=V.size();
	for(auto &[u,v]:B) if(pos[u]>pos[v])
		std::swap(u,v);
	std::sort(B.begin(),B.end(),[&](std::pair<int,int> i,std::pair<int,int> j){
		return pos[i.second]-pos[i.first]<pos[j.second]-pos[j.first];
	});
	for(int i=1;i<=l;i++)
		f[i]=0;
	for(auto [u,v]:B){
		int x=pos[u]+1,y=pos[v]+1;
		if(f[x-1]||f[y-1])
			return flg=0,void();
		for(x=fnd(x);x<y-1;x=fnd(x))
			f[x]=fnd(x+1);
	}
	for(auto [u,v]:B)
		ans[u].emplace_back(v),ans[v].emplace_back(u);
	for(int i=0;i<l;i++)
		ans[V[i]].emplace_back(V[(i+1)%l]),ans[V[i]].emplace_back(V[(i-1+l)%l]);
	for(auto u:A)
		std::sort(ans[u].begin()+cur[u],ans[u].end(),[&](int i,int j){
			return (pos[i]-pos[u]+l)%l<(pos[j]-pos[u]+l)%l;
		});
	for(auto u:A)
		p[u]->nxt=0;
	A.clear(),B.clear();
}

inline void ins(L z){
	if(!flg)
		return;
	int x=z.st->val,y=z.ed->val;
	if(z.st->nxt==z.ed)
		return B.emplace_back(x,y),void();
	std::vector<int> V;
	for(node *u=z.st->nxt;u->val!=y;u=u->nxt)
		V.emplace_back(u->val);
	if(x==y||p[x]->nxt==p[y]||p[y]->nxt==p[x]){
		if(x==y)
			upd(),A.emplace_back(x);
		else
			B.emplace_back(x,y);
		if(p[y]->nxt==p[x])
			std::swap(x,y),std::reverse(V.begin(),V.end());
		int u=x;
		for(auto v:V)
			p[u]->nxt=p[v],u=v,A.emplace_back(v);
		p[u]->nxt=p[y];
	}
	else
		flg=0;
}

int dfn[N],_dfn,low[N],fa[N];
bool vis[N];
std::stack<int> st;

int tot,id[N<<1];
inline int col(int u,int v){
	return (id[u]==id[v]||id[id[u]]==v?id[u]:id[v])-n;
}

std::vector<L> C[N],D;
L F[N];
inline void dfs(int u){
	low[u]=dfn[u]=++_dfn,st.emplace(u);
	for(auto v:E[u])
		if(!dfn[v]){
			fa[v]=u,dfs(v),low[u]=std::min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				if(low[v]==dfn[u])
					D.emplace_back(L(new node(u))+F[v]);
				id[++tot]=u;
				while(1){
					int w=st.top();
					st.pop();
					id[w]=tot;
					if(w==v)
						break;
				}
			}
		}
		else if(v!=fa[u])
			low[u]=std::min(low[u],dfn[v]);
	bool t=0;
	for(auto v:E[u])
		if(fa[v]==u){
			L tmp=L(new node(u))+F[v];
			if(!t&&low[v]==low[u])
				t=1,F[u]=tmp;
			else if(low[v]<dfn[u])
				D.emplace_back(tmp);
		}
		else if(dfn[v]<dfn[u]&&v!=fa[u]){
			L tmp=L(new node(u))+L(new node(v));
			if(!t&&dfn[v]==low[u])
				t=1,F[u]=tmp;
			else
				D.emplace_back(tmp);
		}
}

inline void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		E[i].clear();
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v),u++,v++;
		E[u].emplace_back(v),E[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)
		dfn[i]=vis[i]=0;
	_dfn=0;
	while(st.size())
		st.pop();
	tot=n;
	D.clear();
	for(int i=1;i<=n;i++) if(!dfn[i])
		fa[i]=0,dfs(i);
	for(int i=1;i<=n;i++)
		ans[i].clear();
	flg=1;
	for(int i=1;i<=n;i++)
		p[i]=new node(i);
	A.clear(),B.clear();
	for(int i=1;i<=tot-n;i++)
		C[i].clear();
	std::reverse(D.begin(),D.end());
	for(auto z:D)
		C[col(z.st->val,z.st->nxt->val)].emplace_back(z);
	for(int i=1;i<=tot-n;i++)
		for(auto z:C[i])
			ins(z);
	upd();
	if(!flg)
		return puts("NO"),void();
	puts("YES");
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;i++){
		for(auto u:ans[i])
			printf("%d ",u-1),vis[u]=1;
		for(auto u:E[i]) if(!vis[u])
			printf("%d ",u-1);
		puts("");
		for(auto u:ans[i])
			vis[u]=0;
	}
}

int main(){
	scanf("%d",&T);
	while(T--)
		sol();
}